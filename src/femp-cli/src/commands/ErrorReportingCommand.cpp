#include "ErrorReportingCommand.hpp"

#include <iostream>

int ErrorReportingCommand::execute() {
	std::cout << "Failed to extract a valid command." << std::endl;
	return EXIT_FAILURE;
}
