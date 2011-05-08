#include "AnalysisDialog.h++"

#include <cmath>	// for pow()

#include "../fem/solvers/CholeskySolver.h++"
#include "../fem/solvers/CGSolver.h++"
#include "../fem/solvers/DenseCholeskySolver.h++"
#include "../fem/solvers/UmfpackSolver.h++"

#include "assert.h"


AnalysisDialog::AnalysisDialog(QWidget *parent)
	:QDialog(parent)
{
	setupUi(this);
}


fem::Solver<double> * AnalysisDialog::solver()
{

	switch(toolBoxSolvers->currentIndex())
	{
		case 0:
			{
				fem::CholeskySolver<double> * solver = NULL;
				solver = new fem::CholeskySolver<double>;

				return solver;
			}
			break;

		case 1:
			{
				fem::CGSolver<double> * solver = NULL;
				solver = new fem::CGSolver<double>;

				// set the options
				solver->delta = pow(10,spinBoxDeltaExponent->value());
				solver->max_iterations = spinBoxMaxIterations->value();

				return solver;
			}
			break;

		case 2:
			{
				fem::DenseCholeskySolver<double> * solver = NULL;
				solver = new fem::DenseCholeskySolver<double>;

				return solver;
			}
			break;

		case 3:
			{
				fem::UmfpackSolver<double> * solver = NULL;
				solver = new fem::UmfpackSolver<double>;

				return solver;
			}
			break;

		default:
			assert(false);
			break;
	}

	// this part will never be reached
	return NULL;
}

