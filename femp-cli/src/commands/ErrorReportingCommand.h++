#ifndef ERRORREPORTINGCOMMAND_H
#define ERRORREPORTINGCOMMAND_H

#include "FempCommand.h++"

class ErrorReportingCommand : public FempCommand {
	// FempCommand interface
   public:
	int execute();
};

#endif	// ERRORREPORTINGCOMMAND_H
