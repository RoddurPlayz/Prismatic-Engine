#include "prismatic.h"


void prismInit(std::source_location location)
{
	if (!glfwInit())
		prismThrowError("GLFW", "Crashed while initializing GLFW", -1, location);
}

void prismSetOpenGLVersion(int major, int minor)
{
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, major);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, minor);
}

void prismProcessEvents() { glfwPollEvents(); }

void prismQuit() { glfwTerminate(); }
