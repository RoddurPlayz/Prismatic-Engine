#include <iostream>

#include <prismatic.h>


class Win1 : public PrismScene
{
private:
	PrismShader m_Shader;
	PrismSurface m_Surface{ NULL, NULL };
protected:
	void render()
	{
		window.Fill(0, 255, 0, 255);

		//m_Shader.Bind();

		m_Surface.Draw(m_Shader);

		// m_Shader.Unbind();
		
	}
public:
	Win1(PrismWindow& window) : PrismScene(window)
	{
        m_Shader.VertexFragmentCompileOneFile("Basic.shader", "# VERTEX", "# FRAGMENT");
		std::cout << "OpenGL Version of Window 1: " << window.GetOpenGLVersion() << "\n";
	}
};

class Win2 : public PrismScene
{
private:
	
protected:
	void render()
	{
		window.Fill(0, 0, 255, 255);
	}
public:
	Win2(PrismWindow& window) : PrismScene(window)
	{
		std::cout << "OpenGL Version of Window 2: " << window.GetOpenGLVersion() << "\n";
	}
};


int main()
{
	prismInit();

	prismSetOpenGLVersion(3, 3);

	PrismWindow window1;
	window1.GLFWHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	window1 = prismCreateWindow(800, 600, "Window 1");
	Win1 scene1(window1);

	PrismWindow window2{};
	window2.GLFWHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	window2 = prismCreateWindow(800, 600, "Window 2");
	Win2 scene2(window2);

	while (!window1.ShouldClose() || !window2.ShouldClose())
	{
		prismProcessEvents();
		
		scene1.run();
		scene2.run();

		if (window1.ShouldClose() && !window1.IsDestroyed()) window1.Destroy();
		if (window2.ShouldClose() && !window2.IsDestroyed()) window2.Destroy();
	}

	prismQuit();

	std::cout << "Closed Without Errors" << "\n";

	return 0;
}


/*
// Vertex shader source code
const char* vertexShaderSource = R"glsl(
    #version 330 core
    layout (location = 0) in vec3 position;
    void main() {
        gl_Position = vec4(position, 1.0);
    }
)glsl";

// Fragment shader source code for red triangle
const char* fragmentShaderSourceRed = R"glsl(
    #version 330 core
    out vec4 color;
    void main() {
        color = vec4(1.0, 0.0, 0.0, 1.0); // Red
    }
)glsl";

// Fragment shader source code for green triangle
const char* fragmentShaderSourceGreen = R"glsl(
    #version 330 core
    out vec4 color;
    void main() {
        color = vec4(0.0, 1.0, 0.0, 1.0); // Green
    }
)glsl";

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}

void processInput(GLFWwindow* window) {
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

GLuint compileShader(GLenum type, const char* source) {
    GLuint shader = glCreateShader(type);
    glShaderSource(shader, 1, &source, nullptr);
    glCompileShader(shader);
    return shader;
}

GLuint createProgram(const char* vertexShaderSource, const char* fragmentShaderSource) {
    GLuint vertexShader = compileShader(GL_VERTEX_SHADER, vertexShaderSource);
    GLuint fragmentShader = compileShader(GL_FRAGMENT_SHADER, fragmentShaderSource);
    GLuint shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
    return shaderProgram;
}

int main() {
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window1 = glfwCreateWindow(800, 600, "Red Triangle", nullptr, nullptr);
    if (!window1) {
        std::cerr << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window1);
    glewExperimental = GL_TRUE;
    if (glewInit() != GLEW_OK) {
        std::cerr << "Failed to initialize GLEW" << std::endl;
        return -1;
    }

    GLuint shaderProgramRed = createProgram(vertexShaderSource, fragmentShaderSourceRed);

    float vertices[] = {
        -0.5f, -0.5f, 0.0f,
         0.5f, -0.5f, 0.0f,
         0.0f,  0.5f, 0.0f
    };

    GLuint VAO1, VBO1;
    glGenVertexArrays(1, &VAO1);
    glGenBuffers(1, &VBO1);
    glBindVertexArray(VAO1);
    glBindBuffer(GL_ARRAY_BUFFER, VBO1);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    while (!glfwWindowShouldClose(window1)) {
        processInput(window1);
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        glUseProgram(shaderProgramRed);
        glBindVertexArray(VAO1);
        glDrawArrays(GL_TRIANGLES, 0, 3);
        glfwSwapBuffers(window1);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
*/
