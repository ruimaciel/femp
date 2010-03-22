#include <iostream>
#include <cstdio>
#include <limits>

#include "parsers/json.h"

#include "fem/Model.h++"
#include "fem/Analysis.h++"

#include "ProgramOptions.h++"


int main(int argc, char **argv)
{
	using namespace std;

	// set the program's options
	ProgramOptions options;

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
			cout << "\tcmdline" << endl;
			break;

		case ProgramOptions::OPT_VERSION:	// return the program's version
			//TODO get version from config.h
			cout << "cmdline version 0.1" << endl;
			break;

		case ProgramOptions::OPT_RUN:	// run the model
			{
				using namespace fem;

				//TODO import a model from a file
				fem::Model model;
				FILE *file;	// a pointer to the object controlling the file stream

					// set the input source stream: stdin or file?
				if(options.input_file.empty())
				{
					file = stdin;
				}
				else
				{
					//TODO finish this
				}

					// parse the input strean
				switch(model.import_json(file))
				{
					case Model::ERR_OK:
							// all went well
						if(!options.input_file.empty())
						{
							fclose(file);
						}
							// the rest will happen after the switch() statement
						break;

					default:
						//TODO report an error, exit
						return 1;
						break;
				}

				// TODO run analysis
				Analysis analysis;

				analysis.run(model, model.load_pattern_list[0]);

				// TODO output results
			}
			break;

		default:
			// this part should never be reached
			cerr << "ProgramOptions defaulted" << endl;
			break;
	}


	// exit
	return 0;
}

