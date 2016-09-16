#ifndef FEMP_DENSECHOLESKYSOLVER_HPP
#define FEMP_DENSECHOLESKYSOLVER_HPP

#include <stdio.h>

#include <libfemp/solvers/Solver.h++>
#include <libfemp/AnalysisResult.h++>

#include <libla/solvers/Cholesky.h++>
#include <libla/Matrix.h++>
#include <libla/output.h++>
#include <libla/ProgressIndicatorStrategy.h++>


namespace fem
{

template<typename Scalar>
class DenseCholeskySolver
	: public Solver<Scalar> 
{
	protected:
		lalib::Matrix<Scalar> L;

	public:
		enum Solver<Scalar>::Error initialize(AnalysisResult<Scalar> &result, ProgressIndicatorStrategy *progress);
		enum Solver<Scalar>::Error solve(AnalysisResult<Scalar> &result, ProgressIndicatorStrategy *progress);
		enum Solver<Scalar>::Error cleanup(AnalysisResult<Scalar> &result, ProgressIndicatorStrategy *progress);
};



template<typename Scalar>
enum Solver<Scalar>::Error DenseCholeskySolver<Scalar>::initialize(AnalysisResult<Scalar> &result, ProgressIndicatorStrategy *)
{
	assign(L, result.K);
	return Solver<Scalar>::ERR_OK;
}


template<typename Scalar>
enum Solver<Scalar>::Error DenseCholeskySolver<Scalar>::solve(AnalysisResult<Scalar> &result, ProgressIndicatorStrategy *)
{
	//using namespace std;
	//cout << "K\n" << result.K << "\n\nL:\n" << L << endl;
	lalib::cholesky(result.K, result.d, result.f, L);

	return Solver<Scalar>::ERR_OK;
}


template<typename Scalar>
enum Solver<Scalar>::Error DenseCholeskySolver<Scalar>::cleanup(AnalysisResult<Scalar> &, ProgressIndicatorStrategy *)
{
	return Solver<Scalar>::ERR_OK;
}

}	// namespace fem

#endif
