#include "__shader.h"


PrismShader::PrismShader(std::source_location location)
{
	prismClearOpenGLError();

	m_Program = glCreateProgram();

	m_VertexShaderID = glCreateShader(GL_VERTEX_SHADER);
	const char* vertexShader = m_VertexShaderSource.c_str();
	glShaderSource(m_VertexShaderID, 1, &vertexShader, nullptr);
	glCompileShader(m_VertexShaderID);
	prismCheckShaderError(m_VertexShaderID, "Vertex", m_VertexShaderSource.c_str(), -1,location);

	m_FragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);
	const char* fragmentShader = m_FragmentShaderSource.c_str();
	glShaderSource(m_FragmentShaderID, 1, &fragmentShader, nullptr);
	glCompileShader(m_FragmentShaderID);
	prismCheckShaderError(m_FragmentShaderID, "Fragment", m_FragmentShaderSource.c_str(), -1, location);

	glAttachShader(m_Program, m_VertexShaderID);
	glAttachShader(m_Program, m_FragmentShaderID);
	glLinkProgram(m_Program);
	glValidateProgram(m_Program);

	prismCheckOpenGLError("Crashed while compiling Vertex and Fragment Shader", location);
}

PrismShader::PrismShader(
	std::string vertex_shader_source, std::string fragment_shader_source,
	std::source_location location
)
	:m_VertexShaderSource(vertex_shader_source), m_FragmentShaderSource(fragment_shader_source)
{
	prismClearOpenGLError();

	m_Program = glCreateProgram();

	m_VertexShaderID = glCreateShader(GL_VERTEX_SHADER);
	const char* vertexShader = vertex_shader_source.c_str();
	glShaderSource(m_VertexShaderID, 1, &vertexShader, nullptr);
	glCompileShader(m_VertexShaderID);
	prismCheckShaderError(m_VertexShaderID, "Vertex", m_VertexShaderSource.c_str(), -1, location);

	m_FragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);
	const char* fragmentShader = fragment_shader_source.c_str();
	glShaderSource(m_FragmentShaderID, 1, &fragmentShader, nullptr);
	glCompileShader(m_FragmentShaderID);
	prismCheckShaderError(m_FragmentShaderID, "Fragment", m_FragmentShaderSource.c_str(), -1, location);

	glAttachShader(m_Program, m_VertexShaderID);
	glAttachShader(m_Program, m_FragmentShaderID);
	glLinkProgram(m_Program);
	glValidateProgram(m_Program);

	prismCheckOpenGLError("Crashed while compiling Vertex and Fragment Shader", location);
}

void PrismShader::VertexFragmentCompileSeperateFile(
	const char* vertexShaderPath, const char* fragmentShaderPath,
	std::source_location location
)
{
	prismClearOpenGLError();

	glDetachShader(m_Program, m_VertexShaderID);
	glDetachShader(m_Program, m_FragmentShaderID);
	glDeleteShader(m_VertexShaderID);
	glDeleteShader(m_FragmentShaderID);
	glDeleteProgram(m_Program);

	std::stringstream shaders[2];
	std::string line;
	
	std::ifstream vertexShaderStream(vertexShaderPath);
	if (vertexShaderStream.is_open() == false)
		prismThrowError("Prismatic", "Couldn't open Vertex Shader file", -1, location);

	while (getline(vertexShaderStream, line))
	{
		shaders[0] << line << "\n";
	}
	vertexShaderStream.close();

	std::ifstream fragmentShaderStream(fragmentShaderPath);
	if (fragmentShaderStream.is_open() == false)
		prismThrowError("Prismatic", "Couldn't open Fragment Shader file", -1, location);

	while (getline(fragmentShaderStream, line))
	{
		shaders[1] << line << "\n";
	}
	fragmentShaderStream.close();

	m_VertexShaderSource = shaders[0].str();
	m_FragmentShaderSource = shaders[1].str();

	m_Program = glCreateProgram();

	m_VertexShaderID = glCreateShader(GL_VERTEX_SHADER);
	const char* vertexShader = m_VertexShaderSource.c_str();
	glShaderSource(m_VertexShaderID, 1, &vertexShader, nullptr);
	glCompileShader(m_VertexShaderID);
	prismCheckShaderError(m_VertexShaderID, "Vertex", m_VertexShaderSource.c_str(), -1, location);

	m_FragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);
	const char* fragmentShader = m_FragmentShaderSource.c_str();
	glShaderSource(m_FragmentShaderID, 1, &fragmentShader, nullptr);
	glCompileShader(m_FragmentShaderID);
	prismCheckShaderError(m_FragmentShaderID, "Fragment", m_FragmentShaderSource.c_str(), -1, location);

	glAttachShader(m_Program, m_VertexShaderID);
	glAttachShader(m_Program, m_FragmentShaderID);
	glLinkProgram(m_Program);
	glValidateProgram(m_Program);

	prismCheckOpenGLError("Crashed while compiling Vertex and Fragment Shader", location);
}

void PrismShader::VertexCompileSeperateFile(
	const char* path,
	std::source_location location
)
{
	prismClearOpenGLError();

	glDetachShader(m_Program, m_VertexShaderID);
	glDetachShader(m_Program, m_FragmentShaderID);
	glDeleteShader(m_VertexShaderID);
	glDeleteProgram(m_Program);

	std::stringstream shader;
	std::string line;

	std::ifstream vertexShaderStream(path);
	if (vertexShaderStream.is_open() == false)
		prismThrowError("Prismatic", "Couldn't open Vertex Shader file", -1, location);

	while (getline(vertexShaderStream, line))
	{
		shader << line << "\n";
	}
	vertexShaderStream.close();

	m_VertexShaderSource = shader.str();

	m_Program = glCreateProgram();

	m_VertexShaderID = glCreateShader(GL_VERTEX_SHADER);
	const char* vertexShader = m_VertexShaderSource.c_str();
	glShaderSource(m_VertexShaderID, 1, &vertexShader, nullptr);
	glCompileShader(m_VertexShaderID);
	prismCheckShaderError(m_VertexShaderID, "Vertex", m_VertexShaderSource.c_str(), -1, location);

	glAttachShader(m_Program, m_VertexShaderID);
	glAttachShader(m_Program, m_FragmentShaderID);
	glLinkProgram(m_Program);
	glValidateProgram(m_Program);

	prismCheckOpenGLError("Crashed while compiling Vertex Shader", location);
}

void PrismShader::FragmentCompileSeperateFile(
	const char* path,
	std::source_location location
)
{
	prismClearOpenGLError();

	glDetachShader(m_Program, m_VertexShaderID);
	glDetachShader(m_Program, m_FragmentShaderID);
	glDeleteShader(m_FragmentShaderID);
	glDeleteProgram(m_Program);

	std::stringstream shader;
	std::string line;

	std::ifstream fragmentShaderStream(path);
	if (fragmentShaderStream.is_open() == false)
		prismThrowError("Prismatic", "Couldn't open Fragment Shader file", -1, location);

	while (getline(fragmentShaderStream, line))
	{
		shader << line << "\n";
	}
	fragmentShaderStream.close();

	m_FragmentShaderSource = shader.str();

	m_Program = glCreateProgram();

	m_FragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);
	const char* fragmentShader = m_FragmentShaderSource.c_str();
	glShaderSource(m_FragmentShaderID, 1, &fragmentShader, nullptr);
	glCompileShader(m_FragmentShaderID);
	prismCheckShaderError(m_FragmentShaderID, "Fragment", m_FragmentShaderSource.c_str(), -1, location);

	glAttachShader(m_Program, m_VertexShaderID);
	glAttachShader(m_Program, m_FragmentShaderID);
	glLinkProgram(m_Program);
	glValidateProgram(m_Program);

	prismCheckOpenGLError("Crashed while compiling Fragment Shader", location);
}

void PrismShader::VertexFragmentCompileOneFile(
	const char* path, const char* vertex_shader_line_seperator, const char* fragment_shader_line_seperator,
	std::source_location location
)
{
	prismClearOpenGLError();

	glDetachShader(m_Program, m_VertexShaderID);
	glDetachShader(m_Program, m_FragmentShaderID);
	glDeleteShader(m_VertexShaderID);
	glDeleteShader(m_FragmentShaderID);
	glDeleteProgram(m_Program);

	std::ifstream shaderStream(path);
	if (shaderStream.is_open() == false)
		prismThrowError("Prismatic", "Couldn't open one file Shader to read Vertex and Fragment Shader", -1, location);

	std::string line;
	std::stringstream shaders[2];
	const int vertexMode = 0;
	const int fragmentMode = 1;
	int shaderMode = -1;
	while (getline(shaderStream, line))
	{
		if (line.find(vertex_shader_line_seperator) != std::string::npos)
			shaderMode = vertexMode;

		else if (line.find(fragment_shader_line_seperator) != std::string::npos)
			shaderMode = fragmentMode;

		else
			if (-1 != shaderMode)
				shaders[shaderMode] << line << "\n";
	}
	shaderStream.close();

	m_VertexShaderSource = shaders[0].str();
	m_FragmentShaderSource = shaders[1].str();

	m_Program = glCreateProgram();

	m_VertexShaderID = glCreateShader(GL_VERTEX_SHADER);
	const char* vertexShader = m_VertexShaderSource.c_str();
	glShaderSource(m_VertexShaderID, 1, &vertexShader, nullptr);
	glCompileShader(m_VertexShaderID);
	prismCheckShaderError(m_VertexShaderID, "Vertex", m_VertexShaderSource.c_str(), -1, location);

	m_FragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);
	const char* fragmentShader = m_FragmentShaderSource.c_str();
	glShaderSource(m_FragmentShaderID, 1, &fragmentShader, nullptr);
	glCompileShader(m_FragmentShaderID);
	prismCheckShaderError(m_FragmentShaderID, "Fragment", m_FragmentShaderSource.c_str(), -1, location);

	glAttachShader(m_Program, m_VertexShaderID);
	glAttachShader(m_Program, m_FragmentShaderID);
	glLinkProgram(m_Program);
	glValidateProgram(m_Program);

	prismCheckOpenGLError("Crashed while compiling Vertex and Fragment Shader", location);
}

void PrismShader::VertexCompileOneFile(
	const char* path, const char* line_seperator,
	std::source_location location
)
{
	prismClearOpenGLError();

	glDetachShader(m_Program, m_VertexShaderID);
	glDetachShader(m_Program, m_FragmentShaderID);
	glDeleteShader(m_VertexShaderID);
	glDeleteProgram(m_Program);

	std::ifstream vertexShaderStream(path);
	if (vertexShaderStream.is_open() == false)
		prismThrowError("Prismatic", "Couldn't open one file Shader to read Vertex Shader", -1, location);

	std::string line;
	std::stringstream shader;
	const int vertexMode = 0;
	int shaderMode = -1;
	while (getline(vertexShaderStream, line))
	{
		if (line.find(line_seperator) != std::string::npos)
			shaderMode = vertexMode;

		else
			if (0 == shaderMode)
				shader << line << "\n";
	}
	vertexShaderStream.close();

	m_VertexShaderSource = shader.str();

	m_Program = glCreateProgram();

	m_VertexShaderID = glCreateShader(GL_VERTEX_SHADER);
	const char* vertexShader = m_VertexShaderSource.c_str();
	glShaderSource(m_VertexShaderID, 1, &vertexShader, nullptr);
	glCompileShader(m_VertexShaderID);
	prismCheckShaderError(m_VertexShaderID, "Vertex", m_VertexShaderSource.c_str(), -1, location);

	glAttachShader(m_Program, m_VertexShaderID);
	glAttachShader(m_Program, m_FragmentShaderID);
	glLinkProgram(m_Program);
	glValidateProgram(m_Program);

	prismCheckOpenGLError("Crashed while compiling Vertex Shader", location);
}

void PrismShader::FragmentCompileOneFile(
	const char* path, const char* line_seperator,
	std::source_location location
)
{
	prismClearOpenGLError();

	glDetachShader(m_Program, m_VertexShaderID);
	glDetachShader(m_Program, m_FragmentShaderID);
	glDeleteShader(m_FragmentShaderID);
	glDeleteProgram(m_Program);

	std::ifstream fragmentShaderStream(path);
	if (fragmentShaderStream.is_open() == false)
		prismThrowError("Prismatic", "Couldn't open one file Shader to read Fragment Shader", -1, location);

	std::string line;
	std::stringstream shader;
	const int fragmentMode = 1;
	int shaderMode = -1;
	while (getline(fragmentShaderStream, line))
	{
		if (line.find(line_seperator) != std::string::npos)
			shaderMode = fragmentMode;

		else
			if (1 == shaderMode)
				shader << line << "\n";
	}
	fragmentShaderStream.close();

	m_FragmentShaderSource = shader.str();

	m_Program = glCreateProgram();

	m_FragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);
	const char* fragmentShader = m_FragmentShaderSource.c_str();
	glShaderSource(m_FragmentShaderID, 1, &fragmentShader, nullptr);
	glCompileShader(m_FragmentShaderID);
	prismCheckShaderError(m_FragmentShaderID, "Fragment", m_FragmentShaderSource.c_str(), -1, location);

	glAttachShader(m_Program, m_VertexShaderID);
	glAttachShader(m_Program, m_FragmentShaderID);
	glLinkProgram(m_Program);
	glValidateProgram(m_Program);

	prismCheckOpenGLError("Crashed while compiling Fragment Shader", location);
}

unsigned int PrismShader::GetProgram() { return m_Program; }

const char* PrismShader::GetVertexShaderSource() { return m_VertexShaderSource.c_str(); }

unsigned int PrismShader::GetVertexShaderID() { return m_VertexShaderID; }

const char* PrismShader::GetFragmentShaderSource() { return m_FragmentShaderSource.c_str(); }

unsigned int PrismShader::GetFragmentShaderID() { return m_FragmentShaderID; }

unsigned int PrismShader::GetAttributeLocation(const char* attribute, std::source_location location)
{
	prismClearOpenGLError();

	unsigned int RetVal = glGetAttribLocation(m_Program, attribute);

	prismCheckOpenGLError("Crashed while getting Attribute Location from the Shader", location);

	return RetVal;
}

unsigned int PrismShader::GetUniformLocation(const char* uniform, std::source_location location)
{
	prismClearOpenGLError();

	unsigned int RetVal = glGetUniformLocation(m_Program, uniform);

	prismCheckOpenGLError("Crashed while getting Uniform Location from the Shader", location);

	return RetVal;
}

void PrismShader::Bind(std::source_location location) const
{
	prismClearOpenGLError();

	glUseProgram(m_Program);

	prismCheckOpenGLError("Crashed while binding Shader", location);
}

void PrismShader::Unbind(std::source_location location) const
{
	prismClearOpenGLError();

	glUseProgram(0);

	prismCheckOpenGLError("Crashed while unbinding Shader", location);
}

PrismShader::~PrismShader()
{
	std::source_location location = std::source_location::current();

	prismClearOpenGLError();

	glDeleteShader(m_VertexShaderID);
	glDeleteShader(m_FragmentShaderID);
	glDeleteProgram(m_Program);

	prismCheckOpenGLError("Crashed while destroying Vertex and Fragment Shader", location);
}
