#ifndef ANALYSIS_DIALOG_HPP
#define ANALYSIS_DIALOG_HPP

#include <memory>

#include <QtWidgets/QDialog>
#include <libfemp/LoadPattern.h++>
#include <libfemp/Model.h++>
#include <libfemp/solvers/Solver.h++>

#include <application/interfaces/ILoadPatternRepository.h++>

#include "ui_AnalysisDialog.h"

/**
 * Dialog box designed to input information needed to run the analysis, such as solver
 */
class AnalysisDialog
    : public QDialog,
      private Ui::AnalysisDialog {
    Q_OBJECT

public:
    AnalysisDialog(std::shared_ptr<gui::application::ILoadPatternRepository> load_pattern_repository, QWidget* parent = nullptr);

    /**
     * States which solver has been selected
     * @return	a pointer to a instance of a solver, must be freed afterwards
     */
    fem::Solver<double>* solver();

    /**
     * Returns which load patter the user selected to be analyized
     * @return	counter to the current index
     */
    int loadPattern() const;

protected:
    /**
     * Fills the combo box with the load pattern list from the model
     */
    void loadLoadPatternList(std::shared_ptr<gui::application::ILoadPatternRepository> load_pattern_repository);
};

#endif
