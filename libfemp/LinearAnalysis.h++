#ifndef FEMP_LINEAR_ANALYSIS_HPP
#define FEMP_LINEAR_ANALYSIS_HPP


#include <libla/output.h++>
#include <libla/ProgressIndicatorStrategy.h++>

#include <libfemp/Analysis.h++>
#include <libfemp/AnalysisResult.h++>
#include <libfemp/solvers/Solver.h++>


namespace fem
{


template<typename Scalar>
class LinearAnalysis
	: public Analysis<Scalar>
{
protected:
	Model *m_model;
	LoadPattern *m_load_pattern;
	AnalysisResult *m_result;
	ProgressIndicatorStrategy *m_progress;
	Solver<Scalar>	* m_solver;
	typename Analysis<Scalar>::Error m_error;

public:
	LinearAnalysis();
	~LinearAnalysis();

	void set(Model &model, LoadPattern &lp, AnalysisResult &result, ProgressIndicatorStrategy &progress, Solver<Scalar> *solver);

	/**
	Operator intended to run the analysis through a thread
	**/
	void operator() ();

	bool succeeded() const;
	typename Analysis<Scalar>::Error const error() const;

protected:
	enum Analysis<Scalar>::Error run(Model &model, LoadPattern &lp, AnalysisResult *result, ProgressIndicatorStrategy &progress);
};


}	// namespace fem

#endif
