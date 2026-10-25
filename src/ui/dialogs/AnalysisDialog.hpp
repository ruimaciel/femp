#ifndef FEMP_UI_ANALYSIS_DIALOG_HPP
#define FEMP_UI_ANALYSIS_DIALOG_HPP

#include <application/interfaces/ILoadPatternRepository.hpp>
#include <libfemp/LoadPattern.hpp>
#include <libfemp/Model.hpp>
#include <libfemp/solvers/Solver.hpp>

// Qt includes
#include <QDialog>

// std includes
#include <memory>

/**
 * Dialog box designed to input information needed to run the analysis, such as
 * solver
 */
namespace Ui {
class AnalysisDialog;
}

namespace femp::ui {

class AnalysisDialog : public QDialog {
  Q_OBJECT

public:
  AnalysisDialog(
      femp::application::ILoadPatternRepositoryPtr load_pattern_repository,
      QWidget *parent = nullptr);
  ~AnalysisDialog();

  /**
   * States which solver has been selected
   * @return	a pointer to a instance of a solver, must be freed afterwards
   */
  fem::Solver<double> *solver();

  /**
   * Returns which load patter the user selected to be analyized
   * @return	counter to the current index
   */
  int loadPattern() const;

protected:
  /**
   * Fills the combo box with the load pattern list from the model
   */
  void loadLoadPatternList(
      femp::application::ILoadPatternRepositoryPtr load_pattern_repository);

private:
  std::unique_ptr<Ui::AnalysisDialog> m_ui;
};

} // namespace femp::ui

#endif
