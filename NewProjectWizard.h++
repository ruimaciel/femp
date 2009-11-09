#ifndef NEW_PROJECT_WIZAR_HPP
#define NEW_PROJECT_WIZAR_HPP

#include <QWizard>
#include <QWidget>
#include <QString>

#include "ui/NewProjectWizardPage1.h++"
#include "ui/NewProjectWizardPage2.h++"
#include "ui/NewProjectWizardPageLast.h++"

class NewProjectWizard: public QWizard
{
	Q_OBJECT

	public:
		NewProjectWizard(QWidget *parent = 0, QString basedir = QString());
		~NewProjectWizard();

	private:
		NewProjectWizardPage1 *page1;
		NewProjectWizardPage2 *page2;
		NewProjectWizardPageLast *pageLast;
};

#endif
