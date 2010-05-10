#include "LinearAnalysis.h++"

#include <iostream>
#include <Eigen/Sparse>



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
	using namespace Eigen;

	build_fem_equation(model, lp, true);

	//TODO implement a choice of solver
	d = f;
	SparseLLT<DynamicSparseMatrix<double,RowMajor>,Cholmod>(k).solveInPlace(d);

	return ERR_OK;
}

}

