#include "Error.h"


void prismLog(const char* message)
{
	std::cout << message << "\n";
}

void prismThrowError(const char* type, std::source_location& location, int exit_code)
{
	std::cerr
		<< "[" << type << " Error]" << "\n"
		<< "{" << "\n"
		<< "\t" << "Error function name: " << location.function_name() << "\n"
		<< "\t" << "Error file name: " << location.file_name() << "\n"
		<< "\t" << "Error line: " << location.line() << "\n"
		<< "\t" << "Error column: " << location.column() << "\n"
		<< "}" << "\n";

	exit(-1);
}
