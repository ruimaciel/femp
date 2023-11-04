#include <libfemp/FemException.hpp>

FemException::FemException(const std::string& message) : std::runtime_error(std::string("FEM: " + message)) {}
