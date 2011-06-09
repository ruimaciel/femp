#ifndef LINEAR_ANALYSIS_HPP
#define LINEAR_ANALYSIS_HPP

#include "Analysis.h++"

#include <iostream>
#include <fstream>

#include "../lalib/Matrix.h++"
#include "../lalib/Vector.h++"
#include "../lalib/output.h++"

#include "ProgressIndicatorStrategy.h++"
#include "AnalysisResult.h++"

#include "solvers/Solver.h++"


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
		Solver<Scalar>	* m_solver;

	public:
		LinearAnalysis();
		~LinearAnalysis();

		void set(Model &model, LoadPattern &lp, AnalysisResult<Scalar> *result, ProgressIndicatorStrategy &progress, Solver<Scalar> *solver);

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
	m_solver = NULL;
}


template<typename Scalar>
LinearAnalysis<Scalar>::~LinearAnalysis()
{
}


template<typename Scalar>
void LinearAnalysis<Scalar>::set(Model &model, LoadPattern &lp, AnalysisResult<Scalar> *result, ProgressIndicatorStrategy &progress, Solver<Scalar> *solver)
{
	assert(result != NULL);
	assert(solver != NULL);

	this->m_model = &model;
	this->m_load_pattern = &lp;
	this->m_result = result;
	this->m_progress = &progress;
	this->m_solver = solver;
}


template<typename Scalar>
enum Analysis<Scalar>::Error LinearAnalysis<Scalar>::run(Model &model, LoadPattern &lp, AnalysisResult<Scalar> *result, ProgressIndicatorStrategy &progress)
{
	using namespace std;
	using namespace Eigen;

	// clear existing data structures
	result->clear();

	this->build_fem_equation(model, lp, result, progress);

	result->d.resize(result->f.size());	// is this reallly necessary?

	// temporary matrices
	lalib::Matrix<Scalar, lalib::SparseCRS> my_k;

	//assign(my_k, result->K);
	this->m_solver->initialize(*result, &progress);

	progress.markSectionStart("solve FEM equation");
	progress.markSectionLimit(model.element_list.size());

	this->m_solver->solve(*result, &progress);

	progress.markSectionEnd();

	progress.markSectionStart("recover values");
	this->recoverValues(model, *result);
	progress.markSectionEnd();

	// announce the end
	this->m_solver->cleanup(*result, &progress);
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
