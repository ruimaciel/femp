#ifndef FEMP_UMFPACKSOLVER_HPP
#define FEMP_UMFPACKSOLVER_HPP

#include <stdio.h>

#include <la/Matrix.hpp>
#include <la/ProgressIndicatorStrategy.hpp>
#include <la/output.hpp>
#include <la/solvers/Umfpack.hpp>
#include <libfemp/AnalysisResult.hpp>
#include <libfemp/solvers/Solver.hpp>

namespace fem {

template <typename Scalar>
class UmfpackSolver : public Solver<Scalar> {
	protected:
	lalib::Matrix<Scalar, lalib::SparseCCS> A;

	public:
	enum Solver<Scalar>::Error initialize(Equation& equation, ProgressIndicatorStrategy* progress);
	enum Solver<Scalar>::Error solve(Equation& equation, ProgressIndicatorStrategy* progress);
	enum Solver<Scalar>::Error cleanup(Equation& equation, ProgressIndicatorStrategy* progress);
};

template <typename Scalar>
enum Solver<Scalar>::Error UmfpackSolver<Scalar>::initialize(Equation& equation, ProgressIndicatorStrategy*) {
	assign(A, equation.K);
	return Solver<Scalar>::ERR_OK;
}

template <typename Scalar>
enum Solver<Scalar>::Error UmfpackSolver<Scalar>::solve(Equation& equation, ProgressIndicatorStrategy* progress) {
	lalib::umfpack(A, equation.d, equation.f, progress);

	return Solver<Scalar>::ERR_OK;
}

template <typename Scalar>
enum Solver<Scalar>::Error UmfpackSolver<Scalar>::cleanup(Equation&, ProgressIndicatorStrategy*) {
	return Solver<Scalar>::ERR_OK;
}

}  // namespace fem

#endif
