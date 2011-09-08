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


void ModelWindow::connectSignalsToSlots()
{
}


void ModelWindow::setSelection(Selection)
{
	std::cout << "void ModelWindow::setSelection(Selection)" << std::endl;
}


void ModelWindow::clearSelection()
{
	std::cout << "void ModelWindow::clearSelection()" << std::endl;
}


void ModelWindow::connectToSelectionManager(SelectionManager &selection_manager)
{
	// connects signals to slots
	std::cout << "void ModelWindow::connectToSectionManager(SelectionManager &selection_manager)" << std::endl;

	selection_manager.selection_changed.connect( sigc::mem_fun(this, &ModelWindow::setSelection));
	this->selection_changed.connect( sigc::mem_fun(selection_manager, &SelectionManager::setSelection));
}

