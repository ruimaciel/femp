#include <libfemp/io/import/Parser.h++>

#include <cstring> // for memcpy

Parser::Parser()
{
    buffer[0] = '\0';
    pos = tok = limit = buffer;
    lex_state = 0;
    error.line_number = 0;
}

Parser::~Parser()
{

}

void Parser::fill(std::istream& file)
{
    if (file.good()) {
        // move the remaining unprocessed buffer to the start
        char count = limit - tok;
        memcpy(buffer, tok, count);
        pos = &buffer[pos - tok];
        marker = &buffer[marker - tok];
        tok = buffer;

        // fill the vacant space
        file.read(buffer + count, 1024 - count - 1);
        limit = buffer + count + file.gcount();
        *limit = '\000';
    }
}
