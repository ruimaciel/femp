#ifndef FEMP_NODE_GROUP_HPP
#define FEMP_NODE_GROUP_HPP

#include <vector>
#include <string>

#include <libfemp/Node.h++>


namespace fem
{

/**
Class intended to represent a group of nodes
**/
class NodeGroup
{
protected:
	std::vector<size_t>	m_node_reference_list;

public:
	std::string	label;

	/**
	adds a new node to the list
	**/
	void pushNode(size_t);

	// iterators
	typedef std::vector<size_t>::const_iterator const_iterator;
	std::vector<size_t>::const_iterator begin();	
	std::vector<size_t>::const_iterator end();
	
	// clears the definition;
	void clear();
};

}
#endif
