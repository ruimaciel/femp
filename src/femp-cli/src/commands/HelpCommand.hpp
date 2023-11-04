#ifndef HELPCOMMAND_H
#define HELPCOMMAND_H

#include <boost/program_options.hpp>

#include "FempCommand.hpp"

class HelpCommand : public FempCommand {
	public:
	HelpCommand(boost::program_options::options_description description);

	// FempCommand interface
	public:
	int execute() override final;

	private:
	const boost::program_options::options_description m_description;
};

#endif	// HELPCOMMAND_H
