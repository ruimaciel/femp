#include "ElementRepresentationPolicy.h++"

void 
ElementRepresentationPolicy::setDisplacementPolicy(DisplacementsRepresentationPolicy *displacement)
{
	assert(displacement != NULL);
	this->m_displacement = displacement;
}
