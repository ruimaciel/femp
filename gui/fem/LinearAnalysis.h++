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

#include "ProgressIndicatorStrategy.h++"
#include "AnalysisResult.h++"


namespace fem
{


template<typename Scalar>
class LinearAnalysis
	: public Analysis<Scalar>
{
	protected:
		Model *m_model;
		LoadPattern *m_load_pattern;
		AnalysisResult<Scalar> *m_result;
		ProgressIndicatorStrategy *m_progress;

	public:
		LinearAnalysis();
		~LinearAnalysis();

		void set(Model &model, LoadPattern &lp, AnalysisResult<Scalar> *result, ProgressIndicatorStrategy &progress);

		/**
		Operator intended to run the analysis through a thread
		**/
		void operator() ();

	protected:
		enum Analysis<Scalar>::Error run(Model &model, LoadPattern &lp, AnalysisResult<Scalar> *result, ProgressIndicatorStrategy &progress);
};



template<typename Scalar>
LinearAnalysis<Scalar>::LinearAnalysis()
	: Analysis<Scalar>()
{
	m_model = NULL;
	m_load_pattern = NULL;
	m_result = NULL;
	m_progress = NULL;
}


template<typename Scalar>
LinearAnalysis<Scalar>::~LinearAnalysis()
{
}


template<typename Scalar>
void LinearAnalysis<Scalar>::set(Model &model, LoadPattern &lp, AnalysisResult<Scalar> *result, ProgressIndicatorStrategy &progress)
{
	assert(result != NULL);

	this->m_model = &model;
	this->m_load_pattern = &lp;
	this->m_result = result;
	this->m_progress = &progress;
}


template<typename Scalar>
enum Analysis<Scalar>::Error LinearAnalysis<Scalar>::run(Model &model, LoadPattern &lp, AnalysisResult<Scalar> *result, ProgressIndicatorStrategy &progress)
{
	using namespace std;
	using namespace Eigen;

	// clear existing data structures
	result->clear();

	this->build_fem_equation(model, lp, result, progress);

	result->d = (Scalar)0.0*result->f;	// is this reallly necessary?

	// temporary matrices
	lalib::Matrix<Scalar, lalib::SparseCRS> my_k;
	lalib::Matrix<Scalar, lalib::LowerTriangular> L;

	assign(my_k, result->K);

	progress.markSectionStart("solve FEM equation");
	progress.markSectionLimit(model.element_list.size());

	/*
	//TODO implement a choice of solver
	if(lalib::cg(my_k,d,f,(Scalar)1e-10) != lalib::OK)
	{
		cout << "did not converged" << endl;
		return ERR_SINGULAR_MATRIX;
	}
	// */

	lalib::cholesky(my_k,result->d,result->f,L);

	progress.markSectionEnd();

	/*
	// TODO implement an option to dump a file
	ofstream file;
	file.open("fem.oct");
	dump_octave(file, "K", result->K);
	dump_octave(file, "f", result->f);
	file.close();
	*/


	// set the equation
	progress.markFinish();

	return Analysis<Scalar>::ERR_OK;
}


template<typename Scalar>
void LinearAnalysis<Scalar>::operator() ()
{
	if( this->run(*m_model, *m_load_pattern, m_result, *m_progress) != fem::Analysis<double>::ERR_OK)
	{
		//TODO throw error message
		return;
	}
}


}
#endif
