#include <libfemp/FemException.h++>

FemException::FemException(const std::string& message)
    : std::runtime_error(std::string("FEM: " + message))
{
}
