#include <libfemp/Group.h++>


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

std::string
Group::getLabel() const
{
	return m_label;
}


void
Group::setLabel(std::string label)
{
	this->m_label = label;
}


std::set<node_ref_t>
Group::getNodeReferences() const
{
	return m_node_references;
}


std::set<element_ref_t>
Group::getElementReferences() const
{
	return m_element_references;
}


}	// namespace fem

