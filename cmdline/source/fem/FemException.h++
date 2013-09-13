#ifndef FEM_EXCEPTION_HPP
#define FEM_EXCEPTION_HPP

#include <exception>
#include <string>

/**
Exception classes thrown by the FEM module
**/
class FemException
	: public std::exception
{
	std::string	m_message;	// exception message

public:
	FemException(std::string const &message) throw();
	~FemException() throw();
	virtual const char* what() const throw();
};

#endif
