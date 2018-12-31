#include "Group.h++"


namespace fem
{

void
Group::pushElement(element_ref_t new_element)
{
	this->m_element_references.insert(new_element);
}


void
Group::pushNode(node_ref_t new_node)
{
	this->m_node_references.insert(new_node);
}


void
Group::clear()
{
	this->label.clear();
	this->m_element_references.clear();
	this->m_node_references.clear();
}


}	// namespace fem

