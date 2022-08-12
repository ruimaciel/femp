#ifndef NEWPROJECTWIZARDPAGE2_HPP
#define NEWPROJECTWIZARDPAGE2_HPP

#include <QWizardPage>

#include "ui/ui_NewProjectWizardPage2.h"

class NewProjectWizardPage2 : public QWizardPage, public Ui::NewProjectWizardPage2 {
	Q_OBJECT

   public:
	NewProjectWizardPage2();

	bool validatePage();
};

#endif
