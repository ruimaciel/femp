#include "Selection.h++"

#include <assert.h>


Selection::Selection(fem::Project *project)
{
	assert(project != NULL);
	m_project = project;
}


void 
Selection::addElement(const fem::element_ref_t &ref)
{
	this->m_elements_seleted.insert(ref);
}


void 
Selection::addNode(const fem::node_ref_t &ref)
{
	this->m_nodes_seleted.insert(ref);
}


