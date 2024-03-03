#pragma once


#include <iostream>
#include <source_location>


void prismLog(const char* message);

void prismThrowError(const char* type, std::source_location& location, int exit_code);
