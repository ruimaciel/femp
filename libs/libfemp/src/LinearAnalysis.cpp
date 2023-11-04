#include <fstream>
#include <iostream>
#include <la/Matrix.hpp>
#include <la/Vector.hpp>
#include <libfemp/LinearAnalysis.hpp>

namespace fem {

template <typename Scalar>
LinearAnalysis<Scalar>::LinearAnalysis() : Analysis<Scalar>() {
	m_model = nullptr;
	m_load_pattern = nullptr;
	m_result = nullptr;
	m_progress = nullptr;
	m_solver = nullptr;
	m_error = Analysis<Scalar>::ERR_OK;
}

template <typename Scalar>
LinearAnalysis<Scalar>::~LinearAnalysis() {}

template <typename Scalar>
void LinearAnalysis<Scalar>::set(Model& model, LoadPattern& lp, AnalysisResult& result, ProgressIndicatorStrategy& progress, Solver<Scalar>* solver) {
	assert(solver != nullptr);

	this->m_model = &model;
	this->m_load_pattern = &lp;
	this->m_result = &result;
	this->m_progress = &progress;
	this->m_solver = solver;
}

template <typename Scalar>
bool LinearAnalysis<Scalar>::succeeded() const {
	return (m_error == Analysis<Scalar>::ERR_OK);
}

template <typename Scalar>
typename Analysis<Scalar>::Error const LinearAnalysis<Scalar>::error() const {
	return m_error;
}

template <typename Scalar>
enum Analysis<Scalar>::Error LinearAnalysis<Scalar>::run(Model& model, LoadPattern& lp, AnalysisResult& result, ProgressIndicatorStrategy& progress) {
	using namespace std;
	using namespace Eigen;

	progress.markSectionStart("build FEM equation");
	// clear existing data structures
	result.clear();

	typename Analysis<Scalar>::Error error = Analysis<Scalar>::ERR_OK;

	if ((error = this->buildEquation(model, lp, result, progress)) != Analysis<Scalar>::ERR_OK) {
		// some error happened when building the FEM equation
		return error;
	}

	Equation& equation = result.equation;
	equation.d.resize(equation.f.size());  // is this reallly necessary?

	progress.markSectionEnd();

	// temporary matrices
	lalib::Matrix<Scalar, lalib::SparseCRS> my_k;

	progress.markSectionStart("initializing equation solver");
	this->m_solver->initialize(equation, &progress);
	progress.markSectionEnd();

	progress.markSectionStart("solving FEM equation");
	progress.markSectionLimit(model.numberOfElements());
	this->m_solver->solve(equation, &progress);
	progress.markSectionEnd();

	progress.markSectionStart("generating displacements list");
	this->generateDisplacementsMap(model, result);
	progress.markSectionEnd();

	progress.markSectionStart("recovering values");
	this->recoverValues(model, result);
	progress.markSectionEnd();

	progress.markSectionStart("calculating strain energy");
	this->calculateStrainEnergy(model, result);
	cout << "strain energy: " << result.energy << endl;
	progress.markSectionEnd();

	// announce the end
	this->m_solver->cleanup(equation, &progress);
	progress.markFinish();

	return Analysis<Scalar>::ERR_OK;
}

// explicit template instantiation
template class LinearAnalysis<float>;
template class LinearAnalysis<double>;

}  // namespace fem
