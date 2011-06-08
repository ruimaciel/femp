#ifndef CHOLESKY_SOLVER_HPP
#define CHOLESKY_SOLVER_HPP

#include "Solver.h++"
#include "../AnalysisResult.h++"
#include "../../lalib/solvers/Cholesky.h++"
#include "../../lalib/Matrix.h++"

#include <stdio.h>
#include "../../lalib/output.h++"

#include "../ProgressIndicatorStrategy.h++"

namespace fem
{

template<typename Scalar>
class CholeskySolver
	: public Solver<Scalar> 
{
	protected:
		lalib::Matrix<Scalar, lalib::SparseCRS> L;

	public:
		enum Solver<Scalar>::Error initialize(AnalysisResult<Scalar> &result, ProgressIndicatorStrategy *progress);
		enum Solver<Scalar>::Error solve(AnalysisResult<Scalar> &result, ProgressIndicatorStrategy *progress);
		enum Solver<Scalar>::Error cleanup(AnalysisResult<Scalar> &result, ProgressIndicatorStrategy *progress);
};



template<typename Scalar>
enum Solver<Scalar>::Error CholeskySolver<Scalar>::initialize(AnalysisResult<Scalar> &result, ProgressIndicatorStrategy *)
{
	assign(L, result.K);
	return Solver<Scalar>::ERR_OK;
}


template<typename Scalar>
enum Solver<Scalar>::Error CholeskySolver<Scalar>::solve(AnalysisResult<Scalar> &result, ProgressIndicatorStrategy *)
{
	//using namespace std;
	//cout << "K\n" << result.K << "\n\nL:\n" << L << endl;
	lalib::cholesky(result.K, result.d, result.f, L);

	return Solver<Scalar>::ERR_OK;
}


template<typename Scalar>
enum Solver<Scalar>::Error CholeskySolver<Scalar>::cleanup(AnalysisResult<Scalar> &, ProgressIndicatorStrategy *)
{
	return Solver<Scalar>::ERR_OK;
}

}

#endif
