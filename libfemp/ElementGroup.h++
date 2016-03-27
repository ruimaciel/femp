#ifndef FEMP_ELEMENT_GROUP_HPP
#define FEMP_ELEMENT_GROUP_HPP

#include <vector>
#include <string>


namespace fem
{

/**
Class intended to represent a group of elements
**/
class ElementGroup
{
protected:
	std::vector<size_t>	m_element_reference_list;

public:
	std::string	label;

	/**
	adds a new element to the list
	**/
	void pushElement(size_t);

	// iterators
	typedef std::vector<size_t>::const_iterator const_iterator;
	std::vector<size_t>::const_iterator begin();	
	std::vector<size_t>::const_iterator end();
	
	// clears the definition;
	void clear();
};

}
#endif
