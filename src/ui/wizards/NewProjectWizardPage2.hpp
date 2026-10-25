#ifndef NEWPROJECTWIZARDPAGE2_HPP
#define NEWPROJECTWIZARDPAGE2_HPP

#include <QWizardPage>

#include "ui/ui_NewProjectWizardPage2.h"

namespace femp::ui {

class NewProjectWizardPage2 : public QWizardPage,
                              public Ui::NewProjectWizardPage2 {
  Q_OBJECT

public:
  NewProjectWizardPage2();

  bool validatePage();
};

} // namespace femp::ui

#endif
