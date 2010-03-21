#include "ProgramOptions.h++"



ProgramOptions::ProgramOptions()
{
	//TODO set default options
}


ProgramOptions::~ProgramOptions()
{
}


enum ProgramOptions::Option ProgramOptions::setCommandLineOptions(int argc, char **argv)
{
	//TODO implement support for command line options
	return OPT_RUN;
}

