#ifndef FEMP_EXCEPTION_HPP
#define FEMP_EXCEPTION_HPP

#include <stdexcept>
#include <string>

/**
 * The base calss for all exceptions thrown by FEM routines
 **/
class FemException : public std::runtime_error {
	public:
	explicit FemException(const std::string& message);
};

#endif
