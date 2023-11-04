#include "HelpCommand.hpp"

#include <iostream>

HelpCommand::HelpCommand(boost::program_options::options_description description) : m_description(description) {}

int HelpCommand::execute() {
	std::cout << m_description << std::endl;
	return 1;
}
