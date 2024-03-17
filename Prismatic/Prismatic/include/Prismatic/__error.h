#pragma once


#include <iostream>
#include <source_location>

#define GLEW_STATIC
#include "../GL/glew.h"


void prismLog(const char* message);

void prismThrowError(const char* type, const char* description, int error_code, std::source_location& location);

void prismClearOpenGLError();
void prismCheckOpenGLError(const char* description, std::source_location& location);

void prismCheckShaderError(unsigned int shaderID, const char* shaderType, const char* shader, int error_code, std::source_location& location);
