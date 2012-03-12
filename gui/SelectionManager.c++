#include "SelectionManager.h++"

#include <iostream>	// testing only


void
SelectionManager::setSelection(Selection const &selection)
{
	std::cout << "SelectionManager::setSelection()" << std::endl;
	m_selection = selection;

	this->selection_changed.emit(selection);
}


void
SelectionManager::clearSelection()
{
	std::cout << "SelectionManager::clearSelection()" << std::endl;

	this->m_selection.clear();

	this->selection_cleared.emit();
}


void 
SelectionManager::selectElement(const fem::element_ref_t &ref)
{
	std::cerr << "SelectionManager::selectElement(const fem::element_ref_t &ref)" << std::endl;
	m_selection.selectElement(ref);
}


void 
SelectionManager::deselectElement(const fem::element_ref_t &ref)
{
	std::cerr << "SelectionManager::deselectElement(const fem::element_ref_t &ref)" << std::endl;
	m_selection.deselectElement(ref);
}


void 
SelectionManager::selectNode(const fem::node_ref_t &ref)
{
	std::cerr << "SelectionManager::selectNode(const fem::node_ref_t &ref)" << std::endl;
	m_selection.selectNode(ref);
}


void 
SelectionManager::deselectNode(const fem::node_ref_t &ref)
{
	std::cerr << "SelectionManager::deselectNode(const fem::node_ref_t &ref)" << std::endl;
	m_selection.deselectNode(ref);
}


Selection
SelectionManager::getSelection() const
{
	return m_selection;
}

