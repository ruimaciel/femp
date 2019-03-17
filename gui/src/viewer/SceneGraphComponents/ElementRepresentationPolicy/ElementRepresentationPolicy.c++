#include "ElementRepresentationPolicy.h++"


ElementRepresentationPolicy::ElementRepresentationPolicy()
{
	m_surface_subdivision_level = 1;
}


void 
ElementRepresentationPolicy::setDisplacementPolicy(DisplacementsRepresentationPolicy *displacement)
{
	assert(displacement != NULL);
	this->m_displacement = displacement;
}

