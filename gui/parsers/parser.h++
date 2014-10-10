#ifndef PARSER_HPP
#define PARSER_HPP

#include <fstream>
#include <stack>

#include <libfemp/Model.h++>


/**
Base class for every parser
**/
class Parser
{
	protected:
		std::fstream file;

	public:
		/*
		enum Error {P_OK = 0,
		P_OPEN_FILE,
		P_VERSION,
		P_INVALID_DOCUMENT,	// stumbled on a token that didn't belonged there
		P_UNKNOWN };
		*/
		struct Error
		{
			enum Type
			{
				ERR_OK,
				ERR_INVALID_ELEMENT_REFERENCE,
				ERR_UNSUPPORTED_VERSION,
				ERR_UNKNOWN
			} code;
			std::string message;
			size_t line_number;	// line number where the error occurred 
		} error;

	public:
		Parser();

		virtual enum Error::Type  parse(std::istream &file, fem::Model &model) = 0;

	protected:
		std::stack<int>	ss;	// the LL parser symbol stack

		char buffer[1024];

		// helper variables that are used by the lexer
		char *tok;	// marks the start of the current token
		char *pos; 	// marks the current position
		char *marker;	
		char *limit;	// marks the string limit
		int lex_state;	// lexer state, to avoid grammar ambiguities

		void fill(std::istream &file);
		// virtual int lexer() = 0;
		
		// method which is used to set up the parser table
		virtual void setParserTable() = 0;
};

#endif
