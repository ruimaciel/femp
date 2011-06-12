#include "DisplacementsWindow.h++"

#include "../viewer/DisplacementsViewport.h++"


DisplacementsWindow::DisplacementsWindow(fem::Project &project, ViewportColors &colors, QWidget *parent)
	: MdiWindow(parent), WindowWithResults(project, colors, parent)
{
	viewport = new DisplacementsViewport(project, this);
	this->setCentralWidget(viewport);

	viewport->setColors(colors);

	// create the toolbars
	WindowWithResults::createToolbar(project);

	connectSignalsToSlots();
}


void DisplacementsWindow::connectSignalsToSlots()
{
}


