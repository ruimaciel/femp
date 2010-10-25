#include "LinearAnalysis.h++"

#include <iostream>
#include <fstream>

#include "../lalib/Matrix.h++"
#include "../lalib/Vector.h++"
#include "../lalib/solvers/CG.h++"
#include "../lalib/solvers/Cholesky.h++"
#include "../lalib/output.h++"



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

	/*
	cout << "matrix:" << endl;
	cout << K << endl;
	cout << "vector:" << endl;
	cout << f << endl;
	*/

	//TODO implement a choice of solver
	d = (float)0.0*f;
	lalib::Matrix<float, lalib::SparseCRS> my_k;
	lalib::Matrix<float, lalib::LowerTriangular> L;

	assign(my_k, K);


	if(lalib::cg(my_k,d,f,(float)1e-10) != lalib::OK)
	{
		cout << "did not converged" << endl;
		return ERR_SINGULAR_MATRIX;
	}
	// */

	// lalib::cholesky(my_k,d,f,L);

	ofstream file;
	file.open("fem.oct");
	dump_octave(file, "K", K);
	dump_octave(file, "my_k", my_k);
	dump_octave(file, "f", f);
	dump_octave(file, "L", L);
	file.close();


	//cout << "k pre:\n" << k << endl;
	//SparseLLT<DynamicSparseMatrix<double,RowMajor>,Cholmod>(k).solveInPlace(d);

	//cout << "k pos:\n" << k << endl;

	// set the equation
	p.k = my_k;
	p.f = f;
	p.d = d;
	p.displacements_map = this->displacements_map();

	cout << p.d << endl;
	// calculate U
	lalib::Vector<float> d1 = d;
	d1 = p.k*d;
	cout << "Strain energy: " << dot(d,d1) << endl;


	return ERR_OK;
}

}

