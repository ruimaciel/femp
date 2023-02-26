#include "AnalysisDialog.h++"

#include <QString>
#include <cmath>  // for pow()
#include <libfemp/solvers/CGSolver.h++>
#include <libfemp/solvers/CholeskySolver.h++>
#include <libfemp/solvers/DenseCholeskySolver.h++>
#include <libfemp/solvers/UmfpackSolver.h++>

#include "assert.h"
#include "ui_AnalysisDialog.h"

AnalysisDialog::AnalysisDialog(gui::application::ILoadPatternRepositoryPtr load_pattern_repository, QWidget* parent)
	: QDialog(parent), m_ui(std::make_unique<Ui::AnalysisDialog>()) {
	m_ui->setupUi(this);

	// set the load pattern combo box
	loadLoadPatternList(load_pattern_repository);
}

AnalysisDialog::~AnalysisDialog() = default;

fem::Solver<double>* AnalysisDialog::solver() {
	switch (m_ui->toolBoxSolvers->currentIndex()) {
		case 0: {
			fem::CholeskySolver<double>* solver = nullptr;
			solver = new fem::CholeskySolver<double>;

			return solver;
		} break;

		case 1: {
			fem::CGSolver<double>* solver = nullptr;
			solver = new fem::CGSolver<double>;

			// set the options
			solver->delta = pow(10, m_ui->spinBoxDeltaExponent->value());
			solver->max_iterations = m_ui->spinBoxMaxIterations->value();

			return solver;
		} break;

		case 2: {
			fem::DenseCholeskySolver<double>* solver = nullptr;
			solver = new fem::DenseCholeskySolver<double>;

			return solver;
		} break;

		case 3: {
			fem::UmfpackSolver<double>* solver = nullptr;
			solver = new fem::UmfpackSolver<double>;

			return solver;
		} break;

		default:
			assert(false);
			break;
	}

	// this part will never be reached
	return nullptr;
}

int AnalysisDialog::loadPattern() const {
	// TODO finish this
	return m_ui->comboBoxLoadPattern->currentIndex();
}

void AnalysisDialog::loadLoadPatternList(gui::application::ILoadPatternRepositoryPtr load_pattern_repository) {
	for (auto load_pattern : load_pattern_repository->getLoadPatternList()) {
		QString temp = QString(load_pattern.getLabel().c_str());

		m_ui->comboBoxLoadPattern->addItem(temp);
	}
}
