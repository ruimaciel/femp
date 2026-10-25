#ifndef FEMP_UI_QUADRATUREOPTIONSDIALOG_HPP
#define FEMP_UI_QUADRATUREOPTIONSDIALOG_HPP

#include <libfemp/Analysis.hpp>

// Qt includes
#include <QDialog>

// std includes
#include <memory>

namespace Ui {
class QuadratureRulesOptionsDialog;
}

namespace femp::ui {

class QuadratureRulesOptionsDialog : public QDialog {
  Q_OBJECT

protected:
  fem::Analysis<double> *analysis;

public:
  QuadratureRulesOptionsDialog(fem::Analysis<double> &analysis,
                               QWidget *parent = nullptr);
  ~QuadratureRulesOptionsDialog();

protected slots:
  void setSpinBoxValues();
  void setQuadratureRule();

private:
  std::unique_ptr<Ui::QuadratureRulesOptionsDialog> m_ui;
};

} // namespace femp::ui

#endif
