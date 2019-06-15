#ifndef NEWPROJECTWIZARDPAGELAST_HPP
#define NEWPROJECTWIZARDPAGELAST_HPP

#include "ui/ui_NewProjectWizardPageLast.h"
#include <QWizardPage>
#include <sigc++/sigc++.h> // to side step a compiler error caused by a conflict with Qt and libsigc++

class NewProjectWizardPageLast : public QWizardPage, public Ui_NewProjectWizardPageLast {
    Q_OBJECT

public:
    NewProjectWizardPageLast();

    void initializePage(); // needed to update the fields
};

#endif
