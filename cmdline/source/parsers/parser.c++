#include "parser.h++"

#include <cstring>	// for memcpy


Parser::Parser()
{
	buffer[0] = '\0';
	pos = tok = lim = buffer;
	lex_state = 0;
}


Parser::~Parser()
{
}


void Parser::fill()
{
	// move the remaining unprocessed buffer to the start
	if(lim-tok > 0 )
	{
		memcpy(buffer,tok,lim-tok);
		pos = buffer + (pos - tok);
	}
	else
	{
		pos = buffer;
	}
	tok = buffer;

	// fill the vacant space
	file.read(buffer + (lim-tok), 1024-(lim-buffer));
	lim = buffer + file.gcount();
}
