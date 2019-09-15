#include "AnalysisDialog.h++"

#include <cmath> // for pow()

#include <QString>

#include <libfemp/solvers/CGSolver.h++>
#include <libfemp/solvers/CholeskySolver.h++>
#include <libfemp/solvers/DenseCholeskySolver.h++>
#include <libfemp/solvers/UmfpackSolver.h++>

#include "assert.h"

AnalysisDialog::AnalysisDialog(fem::Model& model, QWidget* parent)
    : QDialog(parent)
{
    setupUi(this);

    //set the load pattern combo box
    loadLoadPatternList(model);
}

fem::Solver<double>* AnalysisDialog::solver()
{

    switch (toolBoxSolvers->currentIndex()) {
    case 0: {
        fem::CholeskySolver<double>* solver = nullptr;
        solver = new fem::CholeskySolver<double>;

        return solver;
    } break;

    case 1: {
        fem::CGSolver<double>* solver = nullptr;
        solver = new fem::CGSolver<double>;

        // set the options
        solver->delta = pow(10, spinBoxDeltaExponent->value());
        solver->max_iterations = spinBoxMaxIterations->value();

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

int AnalysisDialog::loadPattern() const
{
    //TODO finish this
    return comboBoxLoadPattern->currentIndex();
}

void AnalysisDialog::loadLoadPatternList(fem::Model& model)
{
    for (auto load_pattern : model.getLoadPatternList()) {
        QString temp = QString(load_pattern.getLabel().c_str());

        comboBoxLoadPattern->addItem(temp);
    }
}
