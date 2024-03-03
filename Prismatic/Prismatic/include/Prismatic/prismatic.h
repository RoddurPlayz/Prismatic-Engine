#pragma once


#include <iostream>
#include <source_location>

#include "../GL/glew.h"
#include "../GLFW/glfw3.h"

#include "Error.h"
#include "Display.h"


void prismInit(std::source_location location = std::source_location::current());
// TODO: Fix this function which takes in a function pointer and arguments of the function to call it
template <typename Function, typename... Arguments>
void prismInit(Function function, Arguments... arguments, std::source_location location = std::source_location::current());

void prismProcessEvents();

void prismQuit();
// TODO: Fix this function which takes in a function pointer and arguments of the function to call it
template <typename Function, typename... Arguments>
void prismQuit(Function function, Arguments... arguments);
