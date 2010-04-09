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

	build_fem_equation(model, model.load_pattern_list[0], true);

	//TODO implement a choice of solver
	solve_gauss(k, f);

	return ERR_OK;
}

}

