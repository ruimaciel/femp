#include "ElementRepresentationPolicy.h++"

ElementRepresentationPolicy::ElementRepresentationPolicy() {
	m_surface_subdivision_level = 1;
}

ElementRepresentationPolicy::~ElementRepresentationPolicy() {}

void ElementRepresentationPolicy::setDisplacementPolicy(DisplacementsRepresentationPolicy* displacement) {
	assert(displacement != nullptr);
	this->m_displacement = displacement;
}
