#ifndef SOLVER_HPP
#define SOLVER_HPP

#include "../AnalysisResult.h++"

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
		/*
		If necessary, initializes any data structure specific for this solver
		*/
		virtual enum Error initialize(AnalysisResult<Scalar> &result) = 0;
		virtual enum Error solve(AnalysisResult<Scalar> &result) = 0;
		virtual enum Error cleanup(AnalysisResult<Scalar> &result) = 0;
};



/*
template<typename Scalar>
enum Solver<Scalar>::Error Solver<Scalar>::initialize(AnalysisResult<Scalar> &result)
{
	return ERR_UNKNOWN;
}


template<typename Scalar>
enum Solver<Scalar>::Error Solver<Scalar>::solve(AnalysisResult<Scalar> &result)
{
	return ERR_UNKNOWN;
}


template<typename Scalar>
enum Solver<Scalar>::Error Solver<Scalar>::cleanup(AnalysisResult<Scalar> &result)
{
	return ERR_UNKNOWN;
}

*/

}

#endif
