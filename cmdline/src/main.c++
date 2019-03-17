#include <iostream>
#include <cstdio>
#include <limits>

#include <libfemp/Model.h++>
#include <libfemp/LinearAnalysis.h++>
#include <libfemp/FemException.h++>

#include "ProgramOptions.h++"


int main(int argc, char **argv)
{
	using namespace std;
	using namespace fem;

	try
	{
		// declaring the objects
		ProgramOptions options;
		fem::Model model;
		fem::LinearAnalysis<double> analysis;

		// get the remaining options from the command line
		switch(options.setCommandLineOptions(argc, argv))
		{
			case ProgramOptions::OPT_PARSER_ERROR:	// some invalid options passed
				cout << "Invalid option" << endl;
				return 1;
				break;

			case ProgramOptions::OPT_HELP:	// return the help menu
				//TODO finish this
				cout << "usage:" << endl;
				cout << "\tcmdline --help\n";
				cout << "\tcmdline --version\n";
				cout << "\tcmdline <option>*\n\n";
				cout << "options:\n";
				cout << "\t--ips:stiffness (<element type>:<degree>)+\n";
				cout << "\t--ips:domain (<element type>:<degree>)+\n";
				cout << "\t--output-matrix\n";
				cout << endl;
				break;

			case ProgramOptions::OPT_VERSION:	// return the program's version
				//TODO get version from config.h
				cout << "cmdline version 0.1" << endl;
				break;

			case ProgramOptions::OPT_RUN:	// run the model
				break;

			default:
				// this part should never be reached
				cerr << "ProgramOptions defaulted" << endl;
				break;
		}

	}
	catch(FemException e)
	{
		cout << "FemException: " << e.what() << endl;
	}
	catch(std::exception e)
	{
		cout << "exception: " << e.what() << endl;
	}
	catch(...)
	{
		cout << "An exception was thrownn" << endl;
	}

	// exit
	return 0;
}

