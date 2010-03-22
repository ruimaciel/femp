#ifndef PROGRAM_OPTIONS_HPP
#define PROGRAM_OPTIONS_HPP


#include <string>


struct ProgramOptions
{
	// program options
	std::string input_file;	// the name of a file that will be read to input a model
	int digits10;	// default precision


	// other info
	enum Option { 
		OPT_PARSER_ERROR,
		OPT_HELP,
		OPT_VERSION,
		OPT_RUN
	};

	private:	// for the lexer
	enum Tokens {
		TOK_VERSION, 
		TOK_HELP 
	};

	public:
	ProgramOptions();
	~ProgramOptions();


	enum Option setCommandLineOptions(int argc, char **argv);
};

#endif
