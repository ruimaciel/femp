#ifndef FEM_IO_PARSER_HPP
#define FEM_IO_PARSER_HPP

#include <fstream>
#include <libfemp/Model.h++>
#include <stack>

/**
 * Base class for every parser
 */
class Parser {
   public:
	struct Error {
		enum Type { ERR_OK, ERR_INVALID_ELEMENT_REFERENCE, ERR_UNSUPPORTED_VERSION, ERR_UNKNOWN } code;
		std::string message;
		size_t line_number;	 // line number where the error occurred
	} error;

   public:
	Parser();
	virtual ~Parser();

	virtual enum Error::Type parse(std::istream& file, fem::Model& model) = 0;
};

#endif
