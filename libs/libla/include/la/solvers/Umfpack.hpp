#ifndef LALIB_SOLVERS_UMFPACK_HPP
#define LALIB_SOLVERS_UMFPACK_HPP

#include "../Matrix.hpp"
#include "../ProgressIndicatorStrategy.hpp"
#include "../Vector.hpp"
#include "SolverReturnCodes.hpp"

namespace lalib {

/**
Umfpack routine
**/
ReturnCode umfpack(Matrix<double, SparseCCS>& A, Vector<double>& x, Vector<double>& b, ProgressIndicatorStrategy*);
}  // namespace lalib

#endif
