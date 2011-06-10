#include "DisplacementsWindow.h++"

#include "../viewer/DisplacementsViewport.h++"


DisplacementsWindow::DisplacementsWindow(fem::Project &project, ViewportColors &colors, QWidget *parent)
	: MdiWindow(parent)
{
	viewport = new DisplacementsViewport(project, this);
	this->setCentralWidget(viewport);

	viewport->setColors(colors);

	connectSignalsToSlots();
}


void DisplacementsWindow::connectSignalsToSlots()
{
}


