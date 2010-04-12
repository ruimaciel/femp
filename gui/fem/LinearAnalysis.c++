#include "LinearAnalysis.h++"

#include <iostream>

#include "ublas_solvers.h++"


namespace fem
{


LinearAnalysis::LinearAnalysis()
	: Analysis()
{
}


LinearAnalysis::~LinearAnalysis()
{
}


enum LinearAnalysis::Error LinearAnalysis::run(Model &model, LoadPattern &lp)
{
	using namespace std;

	build_fem_equation(model, lp, true);

	//TODO implement a choice of solver
	if(solve_gauss(k, f) == false)
		return ERR_SINGULAR_MATRIX;

	return ERR_OK;
}

}

