#pragma once

#include <iostream>
#include <source_location>

#define GLEW_STATIC
#include "../GL/glew.h"
#include "../GLFW/glfw3.h"

#include "__macros.h"
#include "__error.h"
#include "__display.h"
#include "__shader.h"
#include "__scene.h"
#include "__shape.h"


void prismInit(std::source_location location = std::source_location::current());

void prismSetOpenGLVersion(int major, int minor);

void prismProcessEvents();

void prismQuit();
