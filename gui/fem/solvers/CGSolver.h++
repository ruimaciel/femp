#ifndef CG_SOLVER_HPP
#define CG_SOLVER_HPP

#include "Solver.h++"
#include "../../lalib/solvers/CG.h++"
#include "../../lalib/Matrix.h++"



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

		enum Solver<Scalar>::Error initialize(AnalysisResult<Scalar> &result);
		enum Solver<Scalar>::Error solve(AnalysisResult<Scalar> &result);
		enum Solver<Scalar>::Error cleanup(AnalysisResult<Scalar> &result);
};


template<typename Scalar>
CGSolver<Scalar>::CGSolver()
{
	delta = 1e-100;
	max_iterations = 50;
}


template<typename Scalar>
enum Solver<Scalar>::Error CGSolver<Scalar>::initialize(AnalysisResult<Scalar> &result)
{
	assign(my_k, result.K);

	return Solver<Scalar>::ERR_OK;
}


template<typename Scalar>
enum Solver<Scalar>::Error CGSolver<Scalar>::solve(AnalysisResult<Scalar> &result)
{
	if(lalib::cg(my_k,result.d,result.f, delta, max_iterations) != lalib::OK)
	{
		return Solver<Scalar>::ERR_SINGULAR_MATRIX;
	}

	return Solver<Scalar>::ERR_OK;
}


template<typename Scalar>
enum Solver<Scalar>::Error CGSolver<Scalar>::cleanup(AnalysisResult<Scalar> &result)
{
	return Solver<Scalar>::ERR_OK;
}

}

#endif
