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
	using namespace fem;

	// declaring the objects
	ProgramOptions options;
	fem::Model model;
	Analysis analysis;

	// get the remaining options from the command line
	switch(options.setCommandLineOptions(argc, argv, analysis))
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
			{
					// start JSON output
				cout << "{\n";

				//TODO import a model from a file
				FILE *file;	// a pointer to the object controlling the file stream

					// set the input source stream: stdin or file?
				if(options.input_file.empty())
				{
					file = stdin;
				}
				else
				{
					//TODO finish this
					cerr << "needs finishing" << endl;
					return 0;
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

					// run the analysis
				analysis.build_fem_equation(model, model.load_pattern_list[0]);
					
					// if asked then output FEM equation
				if(options.output_fem)
					analysis.output_fem_equation(cout);

					// solve the equation
				switch(options.solver)
				{
					case ProgramOptions::OPT_S_CHOLESKY:
						//TODO output a meaningful field from the function's return value
						analysis.solve_cholesky();
						break;

					case ProgramOptions::OPT_S_CG:
						//TODO output a meaningful field from the function's return value
						analysis.solve_conjugate_gradient(1e-5);
						break;

					case ProgramOptions::OPT_S_GAUSS:
						//TODO output a meaningful field from the function's return value
						//analysis.solve_gauss();
						analysis.solve_gauss_pivot();
						break;

					default:
						// this bit is only reached if a new solver is added to the command line options and this part is yet to be updated
						cerr << "error: asked for a solver which isn't implemented" << endl;
						return 1;
						break;
				}

				// output displacements field
				analysis.output_displacements(cout);

				// finish JSON output
				cout << "}\n";
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

