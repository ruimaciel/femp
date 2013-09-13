#include "FemException.h++"

FemException::FemException(std::string const &message) throw()
	: m_message(message)
{
}


FemException::~FemException() throw()
{
}


const char* 
FemException::what() const throw()
{
	return m_message.c_str();
}

