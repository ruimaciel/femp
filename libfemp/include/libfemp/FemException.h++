#ifndef FEMP_EXCEPTION
#define FEMP_EXCEPTION

#include <stdexcept>
#include <string>

/**
  * The base calss for all exceptions thrown by FEM routines
  **/
class FemException
    : public std::runtime_error {
public:
    explicit FemException(const std::string& message)
        : std::runtime_error(std::string("FEM: " + message))
    {
    }
};

#endif
