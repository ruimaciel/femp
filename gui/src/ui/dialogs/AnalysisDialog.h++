#ifndef ANALYSIS_DIALOG_HPP
#define ANALYSIS_DIALOG_HPP

#include <QtWidgets/QDialog>
#include <sigc++/sigc++.h> // to side step a compiler error caused by a conflict with Qt and libsigc++

#include <libfemp/LoadPattern.h++>
#include <libfemp/Model.h++>
#include <libfemp/solvers/Solver.h++>

#include "ui_AnalysisDialog.h"

/*
Dialog box designed to input information needed to run the analysis, such as solver
*/
class AnalysisDialog
    : public QDialog,
      private Ui::AnalysisDialog {
    Q_OBJECT

public:
    AnalysisDialog(fem::Model& model, QWidget* parent = nullptr);

    /*
		States which solver has been selected
		@return	a pointer to a instance of a solver, must be freed afterwards
		*/
    fem::Solver<double>* solver();

    /**
		Returns which load patter the user selected to be analyized
		@return	counter to the current index
		**/
    int loadPattern() const;

protected:
    /**
		Fills the combo box with the load pattern list from the model
		**/
    void loadLoadPatternList(fem::Model& model);
};

#endif
