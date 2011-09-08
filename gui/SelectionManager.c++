#include "SelectionManager.h++"

#include <iostream>	// testing only


void 
SelectionManager::setProject(fem::Project &project)
{
	this->m_selection.setProject(project);
}


void
SelectionManager::setSelection(Selection selection)
{
	std::cout << "SelectionManager::setSelection()" << std::endl;
	this->m_selection = selection;

	this->selection_changed.emit(selection);
}


void
SelectionManager::clearSelection()
{
	std::cout << "SelectionManager::clearSelection()" << std::endl;

	this->m_selection.clear();

	this->selection_cleared.emit();
}


Selection
SelectionManager::getSelection()
{
	return this->m_selection;
}

