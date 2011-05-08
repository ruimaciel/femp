#ifndef UMFPACK_SOLVER_HPP
#define UMFPACK_SOLVER_HPP

#include "Solver.h++"
#include "../AnalysisResult.h++"
#include "../../lalib/solvers/Umfpack.h++"
#include "../../lalib/Matrix.h++"

#include <stdio.h>
#include "../../lalib/output.h++"

#include "../ProgressIndicatorStrategy.h++"

namespace fem
{

template<typename Scalar>
class UmfpackSolver
	: public Solver<Scalar> 
{
	protected:
		lalib::Matrix<Scalar, lalib::SparseCCS> A;

	public:
		enum Solver<Scalar>::Error initialize(AnalysisResult<Scalar> &result, ProgressIndicatorStrategy *progress);
		enum Solver<Scalar>::Error solve(AnalysisResult<Scalar> &result, ProgressIndicatorStrategy *progress);
		enum Solver<Scalar>::Error cleanup(AnalysisResult<Scalar> &result, ProgressIndicatorStrategy *progress);
};



template<typename Scalar>
enum Solver<Scalar>::Error UmfpackSolver<Scalar>::initialize(AnalysisResult<Scalar> &result, ProgressIndicatorStrategy *)
{
	assign(A, result.K);
	return Solver<Scalar>::ERR_OK;
}


template<typename Scalar>
enum Solver<Scalar>::Error UmfpackSolver<Scalar>::solve(AnalysisResult<Scalar> &result, ProgressIndicatorStrategy *)
{
	lalib::umfpack(A, result.d, result.f);

	return Solver<Scalar>::ERR_OK;
}


template<typename Scalar>
enum Solver<Scalar>::Error UmfpackSolver<Scalar>::cleanup(AnalysisResult<Scalar> &, ProgressIndicatorStrategy *)
{
	return Solver<Scalar>::ERR_OK;
}

}

#endif
