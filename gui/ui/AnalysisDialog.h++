#ifndef ANALYSIS_DIALOG_HPP
#define ANALYSIS_DIALOG_HPP

#include <QtGui/QDialog>

#include "../fem/solvers/Solver.h++"

#include "ui_AnalysisDialog.h"

/*
Dialog box designed to input information needed to run the analysis, such as solver
*/
class AnalysisDialog
	: public QDialog, private Ui_AnalysisDialog
{
	Q_OBJECT

	public:
		AnalysisDialog(QWidget *parent = NULL);


		/*
		States which solver has been selected
		@return	a pointer to a instance of a solver, must be freed afterwards
		*/
		fem::Solver<double> * solver();
};

#endif
