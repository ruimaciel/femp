#ifndef LINEAR_ANALYSIS_HPP
#define LINEAR_ANALYSIS_HPP

#include "Analysis.h++"

#include <iostream>
#include <fstream>

#include <libla/Matrix.h++>
#include <libla/Vector.h++>
#include <libla/output.h++>
#include <libla/ProgressIndicatorStrategy.h++>

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
		typename Analysis<Scalar>::Error m_error;

	public:
		LinearAnalysis();
		~LinearAnalysis();

		void set(Model &model, LoadPattern &lp, AnalysisResult<Scalar> &result, ProgressIndicatorStrategy &progress, Solver<Scalar> *solver);

		/**
		Operator intended to run the analysis through a thread
		**/
		void operator() ();

		bool succeeded() const;
		typename Analysis<Scalar>::Error const error() const;

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
	m_error = Analysis<Scalar>::ERR_OK;
}


template<typename Scalar>
LinearAnalysis<Scalar>::~LinearAnalysis()
{
}


template<typename Scalar>
void LinearAnalysis<Scalar>::set(Model &model, LoadPattern &lp, AnalysisResult<Scalar> &result, ProgressIndicatorStrategy &progress, Solver<Scalar> *solver)
{
	assert(solver != NULL);

	this->m_model = &model;
	this->m_load_pattern = &lp;
	this->m_result = &result;
	this->m_progress = &progress;
	this->m_solver = solver;
}


template<typename Scalar>
bool 
LinearAnalysis<Scalar>::succeeded() const
{
	return (m_error == Analysis<Scalar>::ERR_OK);
}


template<typename Scalar>
typename Analysis<Scalar>::Error const 
LinearAnalysis<Scalar>::error() const
{
	return m_error;
}


template<typename Scalar>
enum Analysis<Scalar>::Error LinearAnalysis<Scalar>::run(Model &model, LoadPattern &lp, AnalysisResult<Scalar> *result, ProgressIndicatorStrategy &progress)
{
	using namespace std;
	using namespace Eigen;

	progress.markSectionStart("build FEM equation");
	// clear existing data structures
	result->clear();

	typename Analysis<Scalar>::Error error = Analysis<Scalar>::ERR_OK;

	if( ( error = this->build_fem_equation(model, lp, result, progress)) != Analysis<Scalar>::ERR_OK )
	{
		// some error happened when building the FEM equation
		return error;
	}

	result->d.resize(result->f.size());	// is this reallly necessary?
	progress.markSectionEnd();

	// temporary matrices
	lalib::Matrix<Scalar, lalib::SparseCRS> my_k;

	progress.markSectionStart("initializing equation solver");
	this->m_solver->initialize(*result, &progress);
	progress.markSectionEnd();

	progress.markSectionStart("solving FEM equation");
	progress.markSectionLimit(model.element_list.size());
	this->m_solver->solve(*result, &progress);
	progress.markSectionEnd();

	progress.markSectionStart("generating displacements list");
	this->generateDisplacementsMap(model, *result);
	progress.markSectionEnd();

	progress.markSectionStart("recovering values");
	this->recoverValues(model, *result);
	progress.markSectionEnd();

	progress.markSectionStart("calculating strain energy");
	this->calculateStrainEnergy(model, *result);
	cout << "strain energy: " << result->energy << endl;
	progress.markSectionEnd();

	// announce the end
	this->m_solver->cleanup(*result, &progress);
	progress.markFinish();

	return Analysis<Scalar>::ERR_OK;
}


template<typename Scalar>
void LinearAnalysis<Scalar>::operator() ()
{
	m_error = this->run(*m_model, *m_load_pattern, m_result, *m_progress);
}


}
#endif
