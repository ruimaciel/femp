#include "ModelWindow.h++"

#include "../viewer/ModelViewport.h++"
#include <iostream>


ModelWindow::ModelWindow (fem::Project &project, ViewportColors &colors, QWidget *parent)
	: MdiWindow(parent)
{
	viewport = new ModelViewport(project, this);
	this->setCentralWidget(viewport);

	viewport->setColors(colors);

	connectSignalsToSlots();
}


void 
ModelWindow::connectSignalsToSlots()
{
}


void 
ModelWindow::setSelection(Selection)
{
	std::cout << "void ModelWindow::setSelection(Selection)" << std::endl;
}


void 
ModelWindow::clearSelection()
{
	std::cout << "void ModelWindow::clearSelection()" << std::endl;
}

