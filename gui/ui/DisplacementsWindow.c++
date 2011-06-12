#include "DisplacementsWindow.h++"

#include "../viewer/DisplacementsViewport.h++"


DisplacementsWindow::DisplacementsWindow(fem::Project &project, ViewportColors &colors, QWidget *parent)
	: MdiWindow(parent)
{
	viewport = new DisplacementsViewport(project, this);
	this->setCentralWidget(viewport);

	viewport->setColors(colors);

	createResultsToolbar(project);

	connectSignalsToSlots();
}


void DisplacementsWindow::createResultsToolbar(fem::Project &project)
{
	resultsComboBox = new QComboBox(this);
	QString number;

	for(size_t n = 0; n < project.result.size(); n++)
	{
		number.setNum(n);
		resultsComboBox->insertItem(n, number);
	}

	resultsToolBar = addToolBar(tr("Results"));
	resultsToolBar->addWidget(resultsComboBox);
}


void DisplacementsWindow::connectSignalsToSlots()
{
}


