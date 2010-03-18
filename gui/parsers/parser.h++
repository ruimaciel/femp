#ifndef PARSER_HPP
#define PARSER_HPP

#include <fstream>

#include "../fem/Model.h++"


class Parser
{
	protected:
		std::fstream file;

	public:
		enum Error {P_OK = 0,
		P_OPEN_FILE,
		P_VERSION,
		P_INVALID_DOCUMENT,	// stumbled on a token that didn't belonged there
		P_UNKNOWN };

	public:
		Parser();
		~Parser();

		virtual enum Error parse(std::string file_name, fem::Model &model) = 0;

	protected:
		char buffer[1024];

		// helper variables that are used by the lexer
		char *tok;	// marks the start of the current token
		char *pos; 	// marks the current position
		char *marker;	
		char *lim;	// marks the string limit
		int lex_state;	// lexer state, to avoid grammar ambiguities

	protected:
		void fill();	// fills the parser buffer
		// virtual int lexer() = 0;
};

#endif
