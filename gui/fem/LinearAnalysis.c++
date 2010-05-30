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


enum LinearAnalysis::Error LinearAnalysis::run(Model &model, LoadPattern &lp, ProcessedModel &p)
{
	using namespace std;
	using namespace Eigen;

	build_fem_equation(model, lp, true);

	//TODO implement a choice of solver
	d = f;
	//cout << "k pre:\n" << k << endl;
	SparseLLT<DynamicSparseMatrix<double,RowMajor>,Cholmod>(k).solveInPlace(d);
	//cout << "k pos:\n" << k << endl;

	// set the equation
	p.k = k;
	p.f = f;
	p.d = d;
	p.displacements_map = this->displacements_map();

	cout << p.d << endl;
	// calculate U
	cout << "Strain energy: " << (d.transpose()*p.k*d)(0,0) << endl;


	return ERR_OK;
}

}

