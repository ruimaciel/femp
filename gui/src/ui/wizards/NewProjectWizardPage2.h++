#ifndef NEWPROJECTWIZARDPAGE2_HPP
#define NEWPROJECTWIZARDPAGE2_HPP

#include "ui/ui_NewProjectWizardPage2.h"
#include <sigc++/sigc++.h> // to side step a compiler error caused by a conflict with Qt and libsigc++

#include <QWizardPage>

class NewProjectWizardPage2 : public QWizardPage, public Ui::NewProjectWizardPage2 {
    Q_OBJECT

public:
    NewProjectWizardPage2();

    bool validatePage();
};

#endif
