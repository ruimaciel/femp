#ifndef FEMP_SOLVER_HPP
#define FEMP_SOLVER_HPP

#include <la/ProgressIndicatorStrategy.h++>
#include <libfemp/AnalysisResult.h++>

/*
Abstract class for a template method design pattern that implements solvers for
the FEM routine
*/

namespace fem {

template <typename Scalar>
class Solver {
   public:
	enum Error {
		ERR_OK = 0,	 // no error
		ERR_SINGULAR_MATRIX,
		ERR_NEGATIVE_DETERMINANT,
		ERR_UNKNOWN
	};

	virtual ~Solver() {}

	/**
	 * If necessary, initializes any data structure specific for this solver
	 */
	virtual enum Error initialize(Equation& equation, ProgressIndicatorStrategy* progress) = 0;
	virtual enum Error solve(Equation& equation, ProgressIndicatorStrategy* progress) = 0;
	virtual enum Error cleanup(Equation& equation, ProgressIndicatorStrategy* progress) = 0;
};

}  // namespace fem

#endif
