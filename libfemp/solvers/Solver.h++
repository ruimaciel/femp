#ifndef SOLVER_HPP
#define SOLVER_HPP

#include "../AnalysisResult.h++"

#include <libla/ProgressIndicatorStrategy.h++>

/*
Abstract class for a template method design pattern that implements solvers for the FEM routine
*/

namespace fem
{

template<typename Scalar>
class Solver
{
	public:
		enum Error {	
			ERR_OK = 0,	// no error
			ERR_SINGULAR_MATRIX,
			ERR_NEGATIVE_DETERMINANT,
			ERR_UNKNOWN
		};

		virtual ~Solver() {};

		/*
		If necessary, initializes any data structure specific for this solver
		*/
		virtual enum Error initialize(AnalysisResult<Scalar> &result, ProgressIndicatorStrategy *progress) = 0;
		virtual enum Error solve(AnalysisResult<Scalar> &result, ProgressIndicatorStrategy *progress) = 0;
		virtual enum Error cleanup(AnalysisResult<Scalar> &result, ProgressIndicatorStrategy *progress) = 0;
};


}

#endif
