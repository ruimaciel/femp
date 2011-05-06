#ifndef CHOLESKY_SOLVER_HPP
#define CHOLESKY_SOLVER_HPP

#include "Solver.h++"
#include "../../lalib/solvers/Cholesky.h++"
#include "../../lalib/Matrix.h++"

#include "../ProgressIndicatorStrategy.h++"

namespace fem
{

template<typename Scalar>
class CholeskySolver
	: public Solver<Scalar> 
{
	protected:
		lalib::Matrix<Scalar, lalib::LowerTriangular> L;

	public:
		enum Solver<Scalar>::Error initialize(AnalysisResult<Scalar> &result, ProgressIndicatorStrategy *progress);
		enum Solver<Scalar>::Error solve(AnalysisResult<Scalar> &result, ProgressIndicatorStrategy *progress);
		enum Solver<Scalar>::Error cleanup(AnalysisResult<Scalar> &result, ProgressIndicatorStrategy *progress);
};



template<typename Scalar>
enum Solver<Scalar>::Error CholeskySolver<Scalar>::initialize(AnalysisResult<Scalar> &result, ProgressIndicatorStrategy *progress)
{
	return Solver<Scalar>::ERR_OK;
}


template<typename Scalar>
enum Solver<Scalar>::Error CholeskySolver<Scalar>::solve(AnalysisResult<Scalar> &result, ProgressIndicatorStrategy *progress)
{
	lalib::cholesky(result.K, result.d, result.f, L);

	return Solver<Scalar>::ERR_OK;
}


template<typename Scalar>
enum Solver<Scalar>::Error CholeskySolver<Scalar>::cleanup(AnalysisResult<Scalar> &result, ProgressIndicatorStrategy *progress)
{
	return Solver<Scalar>::ERR_OK;
}

}

#endif
