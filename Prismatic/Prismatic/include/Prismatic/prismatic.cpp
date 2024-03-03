#include "prismatic.h"


void prismInit(std::source_location location)
{
	if (!glfwInit())
	{
		prismThrowError("Prismatic", location, -1);
	}
}

template <typename Function, typename... Arguments>
void prismInit(Function function, Arguments... arguments, std::source_location location)
{
	if (!glfwInit())
	{
		prismThrowError("Prismatic", location, -1);
	}

	function(arguments...);
}

void prismProcessEvents()
{
	glfwPollEvents();
}

void prismQuit()
{
	glfwTerminate();
}

template <typename Function, typename... Arguments>
void prismQuit(Function function, Arguments... arguments)
{
	glfwTerminate();

	function(arguments...);
}
