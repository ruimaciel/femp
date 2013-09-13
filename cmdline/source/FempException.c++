#include "FempException.h++"

FempException::FempException(std::string const &message) throw()
	: m_message(message)
{
}


FempException::~FempException() throw()
{
}


const char* 
FempException::what() const throw()
{
	return m_message.c_str();
}

