#include "__error.h"


void prismLog(const char* message) { std::cout << message << "\n"; }

void prismThrowError(const char* type, const char* description, int error_code, std::source_location& location)
{
	std::cerr
		<< "[" << type << " Error]" << "\n"
		<< "{" << "\n"
		<< "\t" << "Error Description: " << description << ";" << "\n"
		<< "\t" << "Error function name: " << location.function_name() << ";" << "\n"
		<< "\t" << "Error file name: " << location.file_name() << ";" << "\n"
		<< "\t" << "Error line: " << location.line() << ";" << "\n"
		<< "\t" << "Error column: " << location.column() << ";" << "\n"
		<< "\t" << "Error code: " << error_code << ";" << "\n"
		<< "}" << "\n";

	exit(error_code);
}

void prismClearOpenGLError() { while (glGetError() != GL_NO_ERROR); }

void prismCheckOpenGLError(const char* description, std::source_location& location)
{
	if (GLenum errorCode = glGetError())
	{
		prismThrowError("OpenGL", description, errorCode, location);
	}
}

void prismCheckShaderError(unsigned int shaderID, const char* shaderType, const char* shader, int error_code, std::source_location& location)
{
	int result;
	glGetShaderiv(shaderID, GL_COMPILE_STATUS, &result);
	if (result == GL_FALSE)
	{
		int message_length;
		glGetShaderiv(shaderID, GL_INFO_LOG_LENGTH, &message_length);
		char* message = (char*)alloca(message_length * sizeof(char));
		glGetShaderInfoLog(shaderID, message_length, &message_length, message);

		std::cerr
			<< "[" << "OpenGL Shader" << " Error]" << "\n"
			<< "{" << "\n"
			<< "\t" << "Shader Type: " << shaderType << ";" << "\n"
			<< "\t" << "Error Description: " << "Failed to compile " << shaderType << "Shader" << ";" << "\n"
			<< "\t" << "Error Reason: " << message
			<< "\t" << "Error function name: " << location.function_name() << ";" << "\n"
			<< "\t" << "Error file name: " << location.file_name() << ";" << "\n"
			<< "\t" << "Error line: " << location.line() << ";" << "\n"
			<< "\t" << "Error column: " << location.column() << ";" << "\n"
			<< "\t" << "Error code: " << error_code << ";" << "\n"
			<< "}" << "\n"
			<< "[" << shaderType << "Shader" << "]:" << "\n"
			<< "\n"
			<< shader << "\n";

		exit(error_code);
	}
}
