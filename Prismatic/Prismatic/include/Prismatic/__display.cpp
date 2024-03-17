#include "__display.h"


PRISMmonitor* prismGetPrimaryMonitor() { return glfwGetPrimaryMonitor(); }

const PRISMvidmode* prismGetVideoMode(PRISMmonitor *monitor) { return glfwGetVideoMode(monitor); }


PrismWindow::PrismWindow() { }

PrismWindow::PrismWindow(
    int width, int height,
    std::string title,
    PRISMmonitor *monitor, PrismWindow *share,
    std::source_location location
)
    :m_Width(width), m_Height(height),
    m_IsFullscreen(false), m_IsResizable(false),
    m_VsyncMode(0),
    m_IsDestroyed(false)
{
    if (share == nullptr)
        m_Window = glfwCreateWindow(width, height, title.c_str(), monitor, nullptr);
	
    else if (share != nullptr)
        m_Window = glfwCreateWindow(width, height, title.c_str(), monitor, share->m_Window);

    if (!m_Window)
    {
        glfwSetWindowShouldClose(m_Window, true);
        prismThrowError("Prismatic", "Crashed while creating a new Window", -1, location);
    }

    glfwMakeContextCurrent(m_Window);

    if (glewInit() != GLEW_OK)
        prismThrowError("GLEW", "Crashed while initializing OpenGL for a new Window", -1, location);

    glfwSwapInterval(0);

    glfwSetWindowAttrib(m_Window, GLFW_RESIZABLE, false);

    m_Title = title;

    __ActiveWindow = this;
    __Windows.push_back(*this);
}

void PrismWindow::GLFWHint(int hint, int value) { glfwWindowHint(hint, value); }

bool PrismWindow::IsActive() { return __ActiveWindow->m_Window == this->m_Window; }

void PrismWindow::MakeActive()
{
    if (__ActiveWindow->m_Window != this->m_Window)
    {
        glfwMakeContextCurrent(m_Window);
        __ActiveWindow = this;
    }
}

const unsigned char* PrismWindow::GetOpenGLVersion() { return glGetString(GL_VERSION); }

bool PrismWindow::ShouldClose() { return glfwWindowShouldClose(m_Window); }

void PrismWindow::SetShouldClose(bool value)
{
    if (!m_IsDestroyed)
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
}

bool PrismWindow::IsDestroyed()
{
    return m_IsDestroyed;
}

void PrismWindow::Destroy()
{
    if (!m_IsDestroyed)
    {
        glfwDestroyWindow(m_Window);
        SetShouldClose(true);
        m_IsDestroyed = true;
    }
}

void PrismWindow::SetSizeLimit(int minwidth, int minheight, int maxwidth, int maxheight)
{ glfwSetWindowSizeLimits(m_Window, minwidth, minheight, maxwidth, maxheight); }

int PrismWindow::GetWidth()
{
    int width;
    int height;
    glfwGetWindowSize(m_Window, &width, &height);

    return width;
}

int PrismWindow::GetHeight()
{
    int width;
    int height;
    glfwGetWindowSize(m_Window, &width, &height);

    return height;
}

void PrismWindow::SetSize(int width, int height) { glfwSetWindowSize(m_Window, width, height); }

bool PrismWindow::IsFullscreen() { return m_IsFullscreen; }

std::string PrismWindow::GetTitle() { return m_Title; }

void PrismWindow::SetTitle(std::string title)
{
    glfwSetWindowTitle(m_Window, title.c_str());
    m_Title = title;
}

void PrismWindow::SetFullscreen(bool value, PRISMmonitor* monitor)
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

bool PrismWindow::IsResizable() { return m_IsResizable; }

void PrismWindow::SetResizable(bool value)
{
    glfwSetWindowAttrib(m_Window, GLFW_RESIZABLE, value);
    m_IsResizable = value;
}

int PrismWindow::GetXPosition()
{
    int x;
    int y;
    glfwGetWindowPos(m_Window, &x, &y);

    return x;
}

int PrismWindow::GetYPosition()
{
    int x;
    int y;
    glfwGetWindowPos(m_Window, &x, &y);

    return y;
}
void PrismWindow::SetPosition(int x, int y)
{
    glfwSetWindowPos(m_Window, x, y);
}

int PrismWindow::GetVsyncMode() { return m_VsyncMode; }

void PrismWindow::SetVsyncMode(int value)
{
    glfwSwapInterval(value);
    m_VsyncMode = value;
}

void PrismWindow::Fill(int red, int green, int blue, int alpha, std::source_location location)
{
    prismClearOpenGLError();

    glClearColor(red / 255.0f, green / 255.0f, blue / 255.0f, alpha / 255.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    std::stringstream ss;
    ss << "Crashed while filling a Window with color value { "
        << red << ", "
        << green << ", "
        << blue << ", "
        << alpha
        << " }.";

    prismCheckOpenGLError(ss.str().c_str(), location);
}


PrismWindow& prismCreateWindow(
    int width, int height,
    std::string title,
    PRISMmonitor* monitor, PrismWindow* share,
    std::source_location location
)
{
    PrismWindow window = {
        width, height,
        title,
        monitor, share,
        location
    };

    return window;
}

void PrismWindow::Update() { glfwSwapBuffers(m_Window); }

bool PrismWindow::GetEventState(PRISMevent EventType) { return glfwGetKey(m_Window, EventType); }


PrismWindow& prismGetActiveWindow() { return *__ActiveWindow; }

std::vector<PrismWindow>& prismGetWindows() { return __Windows; }
