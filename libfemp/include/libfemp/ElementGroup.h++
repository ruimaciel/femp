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
public:
    /**
    adds a new element to the list
    **/
    void pushElement(size_t);

    // iterators
    using const_iterator =  std::vector<size_t>::const_iterator;

    std::vector<size_t>::const_iterator begin();
    std::vector<size_t>::const_iterator end();

    std::string getLabel();
    void setLabel(std::string m_label);

protected:
    std::vector<size_t>	m_element_reference_list;
    std::string	m_label;
};

}	// namespace fem

#endif
