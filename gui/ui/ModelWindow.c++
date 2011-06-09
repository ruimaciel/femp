#include "ModelWindow.h++"


ModelWindow::ModelWindow (fem::Project &project, ViewportColors &colors, QWidget *parent)
	: MdiWindow(parent)
{
	viewport = new ModelViewport(project, this);
	this->setCentralWidget(viewport);

	viewport->setColors(colors);

	connectSignalsToSlots();
}


void ModelWindow::connectSignalsToSlots()
{
}

