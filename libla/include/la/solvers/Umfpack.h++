#ifndef LALIB_SOLVERS_UMFPACK_HPP
#define LALIB_SOLVERS_UMFPACK_HPP

#include "SolverReturnCodes.h++"

#include "../Matrix.h++"
#include "../ProgressIndicatorStrategy.h++"
#include "../Vector.h++"

namespace lalib {

/**
Umfpack routine
**/
ReturnCode umfpack(Matrix<double, SparseCCS>& A, Vector<double>& x, Vector<double>& b, ProgressIndicatorStrategy*);
}

#endif
