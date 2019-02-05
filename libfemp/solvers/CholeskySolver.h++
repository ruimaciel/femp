#ifndef FEMP_CHOLESKYSOLVER_HPP
#define FEMP_CHOLESKYSOLVER_HPP

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
class CholeskySolver
	: public Solver<Scalar>
{
	protected:
		lalib::Matrix<Scalar, lalib::SparseCRS> L;

	public:
		enum Solver<Scalar>::Error initialize(Equation &equation, ProgressIndicatorStrategy *progress);
		enum Solver<Scalar>::Error solve(Equation &equation, ProgressIndicatorStrategy *progress);
		enum Solver<Scalar>::Error cleanup(Equation &equation, ProgressIndicatorStrategy *progress);
};



template<typename Scalar>
enum Solver<Scalar>::Error CholeskySolver<Scalar>::initialize(Equation &equation, ProgressIndicatorStrategy *)
{
	assign(L, equation.K);
	return Solver<Scalar>::ERR_OK;
}


template<typename Scalar>
enum Solver<Scalar>::Error CholeskySolver<Scalar>::solve(Equation &equation, ProgressIndicatorStrategy *)
{
	//using namespace std;
	//cout << "K\n" << K << "\n\nL:\n" << L << endl;
	lalib::cholesky(equation.K, equation.d, equation.f, L);

	return Solver<Scalar>::ERR_OK;
}


template<typename Scalar>
enum Solver<Scalar>::Error CholeskySolver<Scalar>::cleanup(Equation &, ProgressIndicatorStrategy *)
{
	return Solver<Scalar>::ERR_OK;
}

}	// namespace fem

#endif
