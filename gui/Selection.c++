#include "Selection.h++"


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
	m_elements_selected.insert(ref);
}


void 
Selection::deselectElement(const fem::element_ref_t &ref)
{
	m_elements_selected.erase(ref);
}


std::set<fem::element_ref_t> 
Selection::getElementReferences() const
{
	return m_elements_selected;
}


void 
Selection::selectNode(const fem::node_ref_t &ref)
{
	m_nodes_selected.insert(ref);
}


void 
Selection::deselectNode(const fem::node_ref_t &ref)
{
	m_nodes_selected.erase(ref);
}


std::set<fem::node_ref_t> 
Selection::getNodeReferences() const
{
	return m_nodes_selected;
}


