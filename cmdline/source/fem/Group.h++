#ifndef GROUP_HPP
#define GROUP_HPP

#include <set>
#include <string>

#include "Element.h++"
#include "Node.h++"


namespace fem
{

/**
Class intended to represent a group 
**/
class Group
{
public:	// fix this
	std::set<element_ref_t>	m_element_references;
	std::set<node_ref_t>	m_node_references;

public:
	std::string	label;

	/**
	adds a new element to the list
	**/
	void pushElement(element_ref_t);
	void pushNode(node_ref_t);

	// iterators
	std::set<size_t>::const_iterator beginElement();	
	std::set<size_t>::const_iterator endElement();
	std::set<size_t>::const_iterator beginNode();	
	std::set<size_t>::const_iterator endNode();
	
	// clears the definition;
	void clear();
};

}
#endif
