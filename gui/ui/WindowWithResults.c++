#include "WindowWithResults.h++"

#include <QObject>	// for tr()
#include <QString>


void WindowWithResults::createToolbar(QMainWindow *parent, fem::Project &project)
{
	resultsComboBox = new QComboBox(parent);
	QString text;

	for(size_t n = 0; n < project.result.size(); n++)
	{
		text.setNum(n);
		resultsComboBox->insertItem(n, text);
	}

	resultsToolBar = parent->addToolBar(QObject::tr("Results"));
	resultsToolBar->addWidget(resultsComboBox);
}


