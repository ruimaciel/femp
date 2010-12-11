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

#include "AnalysisResult.h++"


namespace fem
{


template<typename Scalar>
class LinearAnalysis
	: public Analysis<Scalar>
{
	public:
		LinearAnalysis();
		~LinearAnalysis();

		enum Analysis<Scalar>::Error run(Model &model, LoadPattern &lp, AnalysisResult<Scalar> *result);
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
enum Analysis<Scalar>::Error LinearAnalysis<Scalar>::run(Model &model, LoadPattern &lp, AnalysisResult<Scalar> *result)
{
	using namespace std;
	using namespace Eigen;

	// clear existing data structures
	result->clear();

	this->build_fem_equation(model, lp, result);

	//TODO implement a choice of solver
	result->d = (Scalar)0.0*result->f;	// is this reallly necessary?

	lalib::Matrix<Scalar, lalib::SparseCRS> my_k;
	lalib::Matrix<Scalar, lalib::LowerTriangular> L;

	assign(my_k, result->K);


	/*
	if(lalib::cg(my_k,d,f,(Scalar)1e-10) != lalib::OK)
	{
		cout << "did not converged" << endl;
		return ERR_SINGULAR_MATRIX;
	}
	// */

	lalib::cholesky(my_k,result->d,result->f,L);

	ofstream file;
	file.open("fem.oct");
	dump_octave(file, "K", result->K);
	/*
	//dump_octave(file, "my_k", my_k);
	dump_octave(file, "f", this->f);
	dump_octave(file, "L", L);
	// */
	file.close();


	//cout << "k pre:\n" << k << endl;
	//SparseLLT<DynamicSparseMatrix<double,RowMajor>,Cholmod>(k).solveInPlace(d);

	//cout << "k pos:\n" << k << endl;

	// set the equation

	cout << result->d << endl;
	// calculate U
	lalib::Vector<Scalar> d1 = result->d;
	d1 = result->K*result->d;
	cout << "Strain energy: " << dot(result->d,d1) << endl;


	return Analysis<Scalar>::ERR_OK;
}

}
#endif
