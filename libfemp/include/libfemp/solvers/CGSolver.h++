#ifndef FEMP_CGSOLVER_HPP
#define FEMP_CGSOLVER_HPP

#include <libfemp/solvers/Solver.h++>

#include <la/solvers/CG.h++>
#include <la/Matrix.h++>
#include <la/ProgressIndicatorStrategy.h++>

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

	enum Solver<Scalar>::Error initialize(Equation & equation, ProgressIndicatorStrategy *progress);
	enum Solver<Scalar>::Error solve(Equation & equation, ProgressIndicatorStrategy *progress);
	enum Solver<Scalar>::Error cleanup(Equation &equation, ProgressIndicatorStrategy *progress);
};


template<typename Scalar>
CGSolver<Scalar>::CGSolver()
{
	delta = 1e-100;
	max_iterations = 50;
}


template<typename Scalar>
enum Solver<Scalar>::Error CGSolver<Scalar>::initialize(Equation &equation, ProgressIndicatorStrategy *)
{
	assign(my_k, equation.K);

	return Solver<Scalar>::ERR_OK;
}


template<typename Scalar>
enum Solver<Scalar>::Error CGSolver<Scalar>::solve(Equation &equation, ProgressIndicatorStrategy *progress)
{
	if(lalib::cg(my_k,equation.d,equation.f, delta, max_iterations, progress) != lalib::OK)
	{
		return Solver<Scalar>::ERR_SINGULAR_MATRIX;
	}

	return Solver<Scalar>::ERR_OK;
}


template<typename Scalar>
enum Solver<Scalar>::Error CGSolver<Scalar>::cleanup(Equation &, ProgressIndicatorStrategy *)
{
	return Solver<Scalar>::ERR_OK;
}


}	// namespace fem

#endif
