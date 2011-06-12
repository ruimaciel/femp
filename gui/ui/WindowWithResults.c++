#include "WindowWithResults.h++"

#include <QString>


WindowWithResults::WindowWithResults(fem::Project &, ViewportColors &, QWidget *parent)
	: MdiWindow(parent)
{
}


void WindowWithResults::createToolbar(fem::Project &project)
{
	resultsComboBox = new QComboBox(this);
	QString text;

	for(size_t n = 0; n < project.result.size(); n++)
	{
		text.setNum(n);
		resultsComboBox->insertItem(n, text);
	}

	resultsToolBar = addToolBar(tr("Results"));
	resultsToolBar->addWidget(resultsComboBox);
}


