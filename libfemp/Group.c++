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


std::set<size_t>::const_iterator 
Group::beginElement()	
{ 
	return this->m_element_references.begin();	
}


std::set<size_t>::const_iterator 
Group::endElement()	
{ 
	return this->m_element_references.end();	
}


std::set<size_t>::const_iterator 
Group::beginNode()	
{ 
	return this->m_node_references.begin();	
}


std::set<size_t>::const_iterator 
Group::endNode()	
{ 
	return this->m_node_references.end();	
}


void
Group::clear()
{
	this->label.clear();
	this->m_element_references.clear();
	this->m_node_references.clear();
}


}	// namespace fem

