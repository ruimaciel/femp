#include "ModelWindow.h++"


ModelWindow::ModelWindow (fem::Model &model, ViewportColors &colors, QWidget *parent)
	: MdiWindow(parent)
{
	viewport = new ModelViewport(&model, this);
	this->setCentralWidget(viewport);

	viewport->setColors(colors);

	connectSignalsToSlots();
}


void ModelWindow::connectSignalsToSlots()
{
}

