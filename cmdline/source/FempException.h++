#ifndef FEMP_EXCEPTION_HPP
#define FEMP_EXCEPTION_HPP

#include <exception>
#include <string>

/**
Base class inherited by all Exception classes used by Femp
**/
class FempException
	: public std::exception
{
	std::string	m_message;	// exception message

public:
	FempException(std::string const &message) throw();
	~FempException() throw();
	virtual const char* what() const throw();
};

#endif
