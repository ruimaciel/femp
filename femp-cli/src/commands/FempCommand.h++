#ifndef FEMPCOMMAND_H
#define FEMPCOMMAND_H

class FempCommand {
	public:
	FempCommand();
	virtual ~FempCommand();

	virtual int execute() = 0;
};

#endif	// FEMPCOMMAND_H
