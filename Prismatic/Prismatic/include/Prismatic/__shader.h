#pragma once


#include <string>
#include <fstream>
#include <sstream>
#include <source_location>

#define GLEW_STATIC
#include "../GL/glew.h"

#include "__error.h"


class PrismShader
{
private:
	unsigned int m_Program;

	std::string m_VertexShaderSource =
		"#version 330 core\n"
		"\n"
		"layout (location = 0) in vec4 position;\n"
		"\n"
		"void main()\n"
		"{\n"
		"	gl_Position = vec4(position.xy, 0.0, 1.0);\n"
		"}\n"
	;
	unsigned int m_VertexShaderID;

	std::string m_FragmentShaderSource =
		"#version 330 core\n"
		"\n"
		"layout (location = 0) out vec4 color;\n"
		"\n"
		"void main()\n"
		"{\n"
		"	color = vec4(1.0, 0.0, 0.0, 1.0);\n"
		"}\n"
	;
	unsigned int m_FragmentShaderID;
public:
	PrismShader(std::source_location location = std::source_location::current());
	PrismShader(
		std::string vertex_shader_source, std::string fragment_shader_source,
		std::source_location location = std::source_location::current()
	);
	
	void VertexFragmentCompileSeperateFile(
		const char* vertex_shader_path, const char* fragment_shader_path,
		std::source_location location = std::source_location::current()
	);
	void VertexCompileSeperateFile(
		const char* path,
		std::source_location location = std::source_location::current()
	);
	void FragmentCompileSeperateFile(
		const char* path,
		std::source_location location = std::source_location::current()
	);

	void VertexFragmentCompileOneFile(
		const char* path, const char* vertex_shader_line_seperator, const char* fragment_shadert_line_seperator,
		std::source_location location = std::source_location::current()
	);
	void VertexCompileOneFile(
		const char* path, const char* line_seperator,
		std::source_location location = std::source_location::current()
	);
	void FragmentCompileOneFile(
		const char* path, const char* line_seperator,
		std::source_location location = std::source_location::current()
	);
	
	unsigned int GetProgram();

	const char* GetVertexShaderSource();
	unsigned int GetVertexShaderID();

	const char* GetFragmentShaderSource();
	unsigned int GetFragmentShaderID();

	unsigned int GetAttributeLocation(const char* attribute, std::source_location locaion = std::source_location::current());
	unsigned int GetUniformLocation(const char* uniform, std::source_location locaion = std::source_location::current());

	void Bind(std::source_location location = std::source_location::current()) const;
	void Unbind(std::source_location location = std::source_location::current()) const;

	~PrismShader();
};
