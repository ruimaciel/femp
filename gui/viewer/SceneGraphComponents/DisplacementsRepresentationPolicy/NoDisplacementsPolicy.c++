#include "NoDisplacementsPolicy.h++"

#include <assert.h>


// Constructors/Destructors
//  

NoDisplacementsPolicy::NoDisplacementsPolicy ( ) 
{
}

NoDisplacementsPolicy::~NoDisplacementsPolicy ( ) 
{ 
}


fem::Point
NoDisplacementsPolicy::operator[](size_t &node_reference)
{
	assert(this->m_model != NULL);

	return this->m_model->node_list[node_reference];
}
