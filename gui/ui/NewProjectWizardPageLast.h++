#ifndef NEWPROJECTWIZARDPAGELAST_HPP
#define NEWPROJECTWIZARDPAGELAST_HPP

#include <sigc++/sigc++.h> 	// to side step a compiler error caused by a conflict with Qt and libsigc++
#include "ui/ui_NewProjectWizardPageLast.h"
#include <QWizardPage>


class NewProjectWizardPageLast: public QWizardPage, public Ui_NewProjectWizardPageLast
{
	Q_OBJECT

	public:
		NewProjectWizardPageLast();
		~NewProjectWizardPageLast();

		void initializePage();	// needed to update the fields
};


#endif

