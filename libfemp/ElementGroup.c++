#include "ElementGroup.h++"


namespace fem
{

void 
ElementGroup::pushElement(size_t new_element)
{
	this->m_element_reference_list.push_back(new_element);
}


std::vector<size_t>::const_iterator 
ElementGroup::begin()	
{ 
	return this->m_element_reference_list.begin();	
}


std::vector<size_t>::const_iterator 
ElementGroup::end()	
{ 
	return this->m_element_reference_list.end();	
}

void
ElementGroup::clear()
{
	this->label.clear();
	this->m_element_reference_list.clear();
}

}
