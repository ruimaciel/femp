#ifndef FEMP_UMFPACKSOLVER_HPP
#define FEMP_UMFPACKSOLVER_HPP

#include <stdio.h>

#include <libfemp/AnalysisResult.h++>
#include <libfemp/solvers/Solver.h++>

#include <la/Matrix.h++>
#include <la/ProgressIndicatorStrategy.h++>
#include <la/output.h++>
#include <la/solvers/Umfpack.h++>

namespace fem {

template <typename Scalar>
class UmfpackSolver
    : public Solver<Scalar> {
protected:
    lalib::Matrix<Scalar, lalib::SparseCCS> A;

public:
    enum Solver<Scalar>::Error initialize(Equation& equation, ProgressIndicatorStrategy* progress);
    enum Solver<Scalar>::Error solve(Equation& equation, ProgressIndicatorStrategy* progress);
    enum Solver<Scalar>::Error cleanup(Equation& equation, ProgressIndicatorStrategy* progress);
};

template <typename Scalar>
enum Solver<Scalar>::Error UmfpackSolver<Scalar>::initialize(Equation& equation, ProgressIndicatorStrategy*)
{
    assign(A, equation.K);
    return Solver<Scalar>::ERR_OK;
}

template <typename Scalar>
enum Solver<Scalar>::Error UmfpackSolver<Scalar>::solve(Equation& equation, ProgressIndicatorStrategy* progress)
{
    lalib::umfpack(A, equation.d, equation.f, progress);

    return Solver<Scalar>::ERR_OK;
}

template <typename Scalar>
enum Solver<Scalar>::Error UmfpackSolver<Scalar>::cleanup(Equation&, ProgressIndicatorStrategy*)
{
    return Solver<Scalar>::ERR_OK;
}

} // namespace fem

#endif
