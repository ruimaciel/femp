#ifndef NEW_PROJECT_WIZAR_HPP
#define NEW_PROJECT_WIZAR_HPP

#include <QString>
#include <QWidget>
#include <QWizard>

#include "Document.hpp"
#include "ui/wizards/NewProjectWizardPage2.hpp"
#include "ui/wizards/NewProjectWizardPage3.hpp"

class NewProjectWizard : public QWizard {
	Q_OBJECT

	public:
	NewProjectWizard(Document& doc, QWidget* parent = nullptr);

	private:
	Q_SIGNALS:
	void newProject(Document::Type type);

	public Q_SLOTS:
	void accept();
};

#endif
