#ifndef LALIB_SOLVERS_UMFPACK_HPP
#define LALIB_SOLVERS_UMFPACK_HPP

#include "../Matrix.h++"
#include "../ProgressIndicatorStrategy.h++"
#include "../Vector.h++"
#include "SolverReturnCodes.h++"

namespace lalib {

/**
Umfpack routine
**/
ReturnCode umfpack(Matrix<double, SparseCCS>& A, Vector<double>& x, Vector<double>& b, ProgressIndicatorStrategy*);
}  // namespace lalib

#endif
