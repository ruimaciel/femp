#ifndef FEMP_CGSOLVER_HPP
#define FEMP_CGSOLVER_HPP

#include <libfemp/solvers/Solver.h++>

#include <libla/solvers/CG.h++>
#include <libla/Matrix.h++>
#include <libla/ProgressIndicatorStrategy.h++>

namespace fem
{

template<typename Scalar>
class CGSolver
	: public Solver<Scalar> 
{
protected:
	lalib::Matrix<Scalar, lalib::SparseCRS> my_k;

public:
	Scalar delta;
	int max_iterations;

	CGSolver();

	enum Solver<Scalar>::Error initialize(AnalysisResult &result, ProgressIndicatorStrategy *progress);
	enum Solver<Scalar>::Error solve(AnalysisResult &result, ProgressIndicatorStrategy *progress);
	enum Solver<Scalar>::Error cleanup(AnalysisResult &result, ProgressIndicatorStrategy *progress);
};


template<typename Scalar>
CGSolver<Scalar>::CGSolver()
{
	delta = 1e-100;
	max_iterations = 50;
}


template<typename Scalar>
enum Solver<Scalar>::Error CGSolver<Scalar>::initialize(AnalysisResult &result, ProgressIndicatorStrategy *)
{
	assign(my_k, result.K);

	return Solver<Scalar>::ERR_OK;
}


template<typename Scalar>
enum Solver<Scalar>::Error CGSolver<Scalar>::solve(AnalysisResult &result, ProgressIndicatorStrategy *progress)
{
	if(lalib::cg(my_k,result.d,result.f, delta, max_iterations, progress) != lalib::OK)
	{
		return Solver<Scalar>::ERR_SINGULAR_MATRIX;
	}

	return Solver<Scalar>::ERR_OK;
}


template<typename Scalar>
enum Solver<Scalar>::Error CGSolver<Scalar>::cleanup(AnalysisResult &, ProgressIndicatorStrategy *)
{
	return Solver<Scalar>::ERR_OK;
}


}	// namespace fem

#endif
