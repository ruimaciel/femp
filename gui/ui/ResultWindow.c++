#include "ResultWindow.h++"


ResultWindow::ResultWindow(fem::Project &project, ViewportColors &colors, QWidget *parent)
	: MdiWindow(parent)
{
	viewport = new DisplacementsViewport(project, this);
	this->setCentralWidget(viewport);

	viewport->setColors(colors);

	connectSignalsToSlots();
}


void ResultWindow::connectSignalsToSlots()
{
}


