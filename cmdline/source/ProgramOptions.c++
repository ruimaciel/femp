#include "ProgramOptions.h++"

#include <iostream>
#include <limits>


ProgramOptions::ProgramOptions()
{
	//TODO set default options
	digits10 = std::numeric_limits<double>::digits10;
}


ProgramOptions::~ProgramOptions()
{
}


enum ProgramOptions::Option ProgramOptions::setCommandLineOptions(int argc, char **argv)
{
	//TODO implement support for command line options
	std::cout.precision(digits10);	// set the default precision

	return OPT_RUN;
}

