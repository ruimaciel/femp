#ifndef NEW_PROJECT_WIZAR_HPP
#define NEW_PROJECT_WIZAR_HPP

#include <QWizard>
#include <QWidget>
#include <QString>

//#include "ui/NewProjectWizardPage1.h++"
#include "ui/NewProjectWizardPage2.h++"
#include "ui/NewProjectWizardPage3.h++"
#include "ui/NewProjectWizardPageLast.h++"

#include "Document.h++"

class NewProjectWizard: public QWizard
{
	Q_OBJECT

	public:
		NewProjectWizard(Document &doc, QWidget *parent = 0);
		~NewProjectWizard();

	private:
		// NewProjectWizardPage1 *page1;
		NewProjectWizardPage2 *page2;	// Select project type
		NewProjectWizardPage3 *page3;	// Import mesh
		NewProjectWizardPageLast *pageLast;

	Q_SIGNALS:
		void newProject(Document::Type type);

	public Q_SLOTS:
		void accept();
};

#endif
