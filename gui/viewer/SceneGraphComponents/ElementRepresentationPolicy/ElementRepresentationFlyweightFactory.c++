#include "ElementRepresentationFlyweightFactory.h++"

#include <assert.h>


ElementRepresentationFlyweightFactory::ElementRepresentationFlyweightFactory ( ) 
{
}


ElementRepresentationFlyweightFactory::~ElementRepresentationFlyweightFactory ( ) 
{ 
}


void 
ElementRepresentationFlyweightFactory::setDisplacementsRepresentationPolicy(DisplacementsRepresentationPolicy *displacements)
{
	assert(displacements != NULL);

	m_opaque_policy.setDisplacementPolicy(displacements);
	m_color_policy.setDisplacementPolicy(displacements);
	//m_tensor_policy.setDisplacementPolicy(displacements);
}
