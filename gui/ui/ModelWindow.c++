#include "ModelWindow.h++"

#include "../viewer/ModelViewport.h++"
#include <iostream>


ModelWindow::ModelWindow (fem::Project &project, ViewportColors &colors, QWidget *parent)
	: MdiWindow(parent), 
	WindowWithWireframe(parent)
{
	viewport = new ModelViewport(project, this);
	this->setCentralWidget(viewport);

	viewport->setColors(colors);

	WindowWithWireframe::createToolbar();

	connectSignalsToSlots();
}


void 
ModelWindow::connectSignalsToSlots()
{
	// nasty hack to connect libsigc++ signal
	MdiWindow::connectSignalsToSlots();
}


