#include "Display.h"


PRISMmonitor* prismGetPrimaryMonitor()
{
    return glfwGetPrimaryMonitor();
}

const PRISMvidmode* prismGetVideoMode(PRISMmonitor *monitor)
{
    return glfwGetVideoMode(monitor);
}


PRISMwindow::PRISMwindow(int width, int height, std::string title, PRISMmonitor *monitor, PRISMwindow *share, std::source_location location)
    :m_Width(width), m_Height(height), m_IsFullscreen(false), m_IsResizable(false), m_VsyncMode(0)
{
    if (share == nullptr)
    {
        m_Window = glfwCreateWindow(width, height, title.c_str(), monitor, nullptr);
    }
	
    else if (share != nullptr)
    {
        m_Window = glfwCreateWindow(width, height, title.c_str(), monitor, share->m_Window);
    }

    if (!m_Window)
    {
        glfwSetWindowShouldClose(m_Window, true);
        prismThrowError("Prismatic", location, -1);
    }

    glfwMakeContextCurrent(m_Window);
    glfwSwapInterval(0);

    glfwSetWindowAttrib(m_Window, GLFW_RESIZABLE, false);

    m_Title = title;

    __ActiveWindow = this;
    __Windows.push_back(*this);
}

bool PRISMwindow::IsActive()
{
    return __ActiveWindow->m_Window == this->m_Window;
}

void PRISMwindow::MakeActive()
{
    if (__ActiveWindow->m_Window != this->m_Window)
    {
        glfwMakeContextCurrent(m_Window);
        __ActiveWindow = this;
    }
}

bool PRISMwindow::ShouldClose()
{
    return glfwWindowShouldClose(m_Window);
}

// TODO: Fix this function which takes in a function pointer and arguments of the function to call it
template <typename Function, typename... Arguments>
bool PRISMwindow::ShouldClose(Function function, Arguments... arguments)
{
    bool ReturnValue = glfwWindowShouldClose(m_Window);

    if (ReturnValue == true)
    {
        function(arguments...);
    }

    return ReturnValue;
}

void PRISMwindow::SetShouldClose(bool value)
{
    if (value == true)
    {
        if (m_ShouldWindowClose == false)
        {
            glfwSetWindowShouldClose(m_Window, value);
            __Windows.push_back(*this);
        }
    }
    else if (value == false)
    {
        if (m_ShouldWindowClose == true)
        {
            glfwSetWindowShouldClose(m_Window, value);

            for (int it = 0; it != __Windows.size(); ++it)
            {
                if (__Windows[it].m_Window == this->m_Window)
                {
                    __Windows.erase(it + __Windows.begin());
                    break;
                }
            }
        }
    }
}

void PRISMwindow::SetSizeLimit(int minwidth, int minheight, int maxwidth, int maxheight)
{
    glfwSetWindowSizeLimits(m_Window, minwidth, minheight, maxwidth, maxheight);
}

int PRISMwindow::GetWidth()
{
    int width;
    int height;
    glfwGetWindowSize(m_Window, &width, &height);

    return width;
}

int PRISMwindow::GetHeight()
{
    int width;
    int height;
    glfwGetWindowSize(m_Window, &width, &height);

    return height;
}

void PRISMwindow::SetSize(int width, int height)
{
    glfwSetWindowSize(m_Window, width, height);
}

bool PRISMwindow::IsFullscreen()
{
    return m_IsFullscreen;
}

std::string PRISMwindow::GetTitle()
{
    return m_Title;
}

void PRISMwindow::SetTitle(std::string title)
{
    glfwSetWindowTitle(m_Window, title.c_str());
    m_Title = title;
}

void PRISMwindow::SetFullscreen(bool value, PRISMmonitor* monitor)
{
    if (value == true)
    {
        if (m_IsFullscreen == false)
        {
            glfwGetWindowPos(m_Window, &m_Xpos, &m_Ypos);
            glfwGetWindowSize(m_Window, &m_Width, &m_Height);

            const GLFWvidmode* mode = glfwGetVideoMode(monitor);
            glfwSetWindowMonitor(m_Window, monitor, 0, 0, mode->width, mode->height, mode->refreshRate);

            m_IsFullscreen = true;
        }
    }

    else if (value == false)
    {
        if (m_IsFullscreen == true)
        {
            glfwSetWindowMonitor(m_Window, NULL, 0, 0, m_Width, m_Height, 0);

            glfwSetWindowPos(m_Window, m_Xpos, m_Ypos);
            glfwSetWindowSize(m_Window, m_Width, m_Height);

            m_IsFullscreen = false;
        }
    }
}

bool PRISMwindow::IsResizable()
{
    return m_IsResizable;
}

void PRISMwindow::SetResizable(bool value)
{
    glfwSetWindowAttrib(m_Window, GLFW_RESIZABLE, value);
    m_IsResizable = value;
}

int PRISMwindow::GetXPosition()
{
    int x;
    int y;
    glfwGetWindowPos(m_Window, &x, &y);

    return x;
}

int PRISMwindow::GetYPosition()
{
    int x;
    int y;
    glfwGetWindowPos(m_Window, &x, &y);

    return y;
}
void PRISMwindow::SetPosition(int x, int y)
{
    glfwSetWindowPos(m_Window, x, y);
}

int PRISMwindow::GetVsyncMode()
{
    return m_VsyncMode;
}

void PRISMwindow::SetVsyncMode(int value)
{
    glfwSwapInterval(value);
    m_VsyncMode = value;
}

void PRISMwindow::Fill(int red, int green, int blue, int alpha)
{
    glClearColor(red/255.0f, green/255.0f, blue/255.0f, alpha/255.0f);
    glClear(GL_COLOR_BUFFER_BIT);
}

void PRISMwindow::Update()
{
    glfwSwapBuffers(m_Window);
}


PRISMwindow& prismGetActiveWindow()
{
    return *__ActiveWindow;
}

std::vector<PRISMwindow>& prismGetWindows()
{
    return __Windows;
}
