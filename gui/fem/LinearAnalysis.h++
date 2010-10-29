#ifndef LINEAR_ANALYSIS_HPP
#define LINEAR_ANALYSIS_HPP

#include "Analysis.h++"

#include <iostream>
#include <fstream>

#include "../lalib/Matrix.h++"
#include "../lalib/Vector.h++"
#include "../lalib/solvers/CG.h++"
#include "../lalib/solvers/Cholesky.h++"
#include "../lalib/output.h++"


namespace fem
{


template<typename Scalar>
class LinearAnalysis
	: public Analysis<Scalar>
{
	public:
		LinearAnalysis();
		~LinearAnalysis();

		enum Analysis<Scalar>::Error run(Model &model, LoadPattern &lp);
};



template<typename Scalar>
LinearAnalysis<Scalar>::LinearAnalysis()
	: Analysis<Scalar>()
{
}


template<typename Scalar>
LinearAnalysis<Scalar>::~LinearAnalysis()
{
}


template<typename Scalar>
enum Analysis<Scalar>::Error LinearAnalysis<Scalar>::run(Model &model, LoadPattern &lp)
{
	using namespace std;
	using namespace Eigen;

	this->build_fem_equation(model, lp);

	//TODO implement a choice of solver
	this->d = (Scalar)0.0*this->f;
	lalib::Matrix<Scalar, lalib::SparseCRS> my_k;
	lalib::Matrix<Scalar, lalib::LowerTriangular> L;

	assign(my_k, this->K);


	/*
	if(lalib::cg(my_k,d,f,(Scalar)1e-10) != lalib::OK)
	{
		cout << "did not converged" << endl;
		return ERR_SINGULAR_MATRIX;
	}
	// */

	lalib::cholesky(my_k,this->d,this->f,L);

	ofstream file;
	file.open("fem.oct");
	dump_octave(file, "K", this->K);
	dump_octave(file, "my_k", my_k);
	dump_octave(file, "f", this->f);
	dump_octave(file, "L", L);
	file.close();


	//cout << "k pre:\n" << k << endl;
	//SparseLLT<DynamicSparseMatrix<double,RowMajor>,Cholmod>(k).solveInPlace(d);

	//cout << "k pos:\n" << k << endl;

	// set the equation
	/*
	p.k = my_k;
	p.f = this->f;
	p.d = this->d;
	p.displacements_map = this->displacements_map();
	*/

	cout << this->d << endl;
	// calculate U
	lalib::Vector<Scalar> d1 = this->d;
	d1 = this->K*this->d;
	cout << "Strain energy: " << dot(this->d,d1) << endl;


	return Analysis<Scalar>::ERR_OK;
}

}
#endif
