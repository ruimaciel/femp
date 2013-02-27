#include "Selection.h++"

#include <assert.h>


void 
Selection::clear()
{
	this->m_elements_selected.clear();
	this->m_nodes_selected.clear();
}


void 
Selection::setSelection(Selection const &selection)
{
	this->m_elements_selected = selection.m_elements_selected;
	this->m_nodes_selected = selection.m_nodes_selected;
}


void 
Selection::selectElement(const fem::element_ref_t &ref)
{
	//std::cerr << "Selection::selectElement(const fem::element_ref_t &ref)" << std::endl;
	m_elements_selected.insert(ref);
}


void 
Selection::deselectElement(const fem::element_ref_t &ref)
{
	//std::cerr << "Selection::selectElement(const fem::element_ref_t &ref)" << std::endl;
	m_elements_selected.erase(ref);
}


void 
Selection::selectNode(const fem::node_ref_t &ref)
{
	//std::cerr << "Selection::selectNode(const fem::node_ref_t &ref)" << std::endl;
	m_nodes_selected.insert(ref);
}


void 
Selection::deselectNode(const fem::node_ref_t &ref)
{
	//std::cerr << "Selection::deselectNode(const fem::node_ref_t &ref)" << std::endl;
	m_nodes_selected.erase(ref);
}

