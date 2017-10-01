#ifndef FEMP_UMFPACKSOLVER_HPP
#define FEMP_UMFPACKSOLVER_HPP

#include <stdio.h>

#include <libfemp/solvers/Solver.h++>
#include <libfemp/AnalysisResult.h++>

#include <libla/solvers/Umfpack.h++>
#include <libla/Matrix.h++>
#include <libla/output.h++>
#include <libla/ProgressIndicatorStrategy.h++>

namespace fem
{

template<typename Scalar>
class UmfpackSolver
	: public Solver<Scalar> 
{
protected:
	lalib::Matrix<Scalar, lalib::SparseCCS> A;

public:
	enum Solver<Scalar>::Error initialize(AnalysisResult &result, ProgressIndicatorStrategy *progress);
	enum Solver<Scalar>::Error solve(AnalysisResult &result, ProgressIndicatorStrategy *progress);
	enum Solver<Scalar>::Error cleanup(AnalysisResult &result, ProgressIndicatorStrategy *progress);
};



template<typename Scalar>
enum Solver<Scalar>::Error UmfpackSolver<Scalar>::initialize(AnalysisResult &result, ProgressIndicatorStrategy *)
{
	assign(A, result.K);
	return Solver<Scalar>::ERR_OK;
}


template<typename Scalar>
enum Solver<Scalar>::Error UmfpackSolver<Scalar>::solve(AnalysisResult &result, ProgressIndicatorStrategy *progress)
{
	lalib::umfpack(A, result.d, result.f, progress);

	return Solver<Scalar>::ERR_OK;
}


template<typename Scalar>
enum Solver<Scalar>::Error UmfpackSolver<Scalar>::cleanup(AnalysisResult &, ProgressIndicatorStrategy *)
{
	return Solver<Scalar>::ERR_OK;
}


}	// namespace fem

#endif
