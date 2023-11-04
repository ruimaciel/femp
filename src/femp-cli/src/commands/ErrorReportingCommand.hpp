#ifndef ERRORREPORTINGCOMMAND_H
#define ERRORREPORTINGCOMMAND_H

#include "FempCommand.hpp"

class ErrorReportingCommand : public FempCommand {
	// FempCommand interface
	public:
	int execute();
};

#endif	// ERRORREPORTINGCOMMAND_H
