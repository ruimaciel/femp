#ifndef FEMP_LINEARANALYSIS_HPP
#define FEMP_LINEARANALYSIS_HPP

// libfemp includes
#include <libfemp/Analysis.h++>
#include <libfemp/AnalysisResult.h++>
#include <libfemp/LoadPattern.h++>
#include <libfemp/Model.h++>
#include <libfemp/solvers/Solver.h++>

// la includes
#include <la/ProgressIndicatorStrategy.h++>
#include <la/output.h++>

namespace fem {

template <typename Scalar>
class LinearAnalysis : public Analysis<Scalar> {
	public:
	LinearAnalysis();
	~LinearAnalysis();

	void set(Model& model, LoadPattern& lp, AnalysisResult& result, ProgressIndicatorStrategy& progress, Solver<Scalar>* solver);

	bool succeeded() const;

	typename Analysis<Scalar>::Error const error() const;

	enum Analysis<Scalar>::Error run(Model& model, LoadPattern& lp, AnalysisResult& result, ProgressIndicatorStrategy& progress) override;

	protected:
	Model* m_model;
	LoadPattern* m_load_pattern;
	AnalysisResult* m_result;
	ProgressIndicatorStrategy* m_progress;
	Solver<Scalar>* m_solver;
	typename Analysis<Scalar>::Error m_error;
};

}  // namespace fem

#endif
