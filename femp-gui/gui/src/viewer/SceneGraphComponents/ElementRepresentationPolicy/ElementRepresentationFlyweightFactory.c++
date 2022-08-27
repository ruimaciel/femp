#include "ElementRepresentationFlyweightFactory.h++"

#include <assert.h>

ElementRepresentationFlyweightFactory::ElementRepresentationFlyweightFactory() {
	setSurfaceSubdivisionLevel(2);	// 6 elements per side by default
}

void ElementRepresentationFlyweightFactory::setDisplacementsRepresentationPolicy(DisplacementsRepresentationPolicy* displacements) {
	assert(displacements != nullptr);

	m_opaque_policy.setDisplacementPolicy(displacements);
	m_gradient_policy.setDisplacementPolicy(displacements);
}

ElementRepresentationPolicy* ElementRepresentationFlyweightFactory::opaque() {
	return &m_opaque_policy;
}

ElementRepresentationPolicy* ElementRepresentationFlyweightFactory::gradient() {
	return &m_gradient_policy;
}

void ElementRepresentationFlyweightFactory::setTriangleWireframeRendering(bool const state) {
	m_opaque_policy.setTriangleWireframeRendering(state);
}

void ElementRepresentationFlyweightFactory::toggleTriangleWireframeRendering() {
	m_opaque_policy.toggleTriangleWireframeRendering();
}

void ElementRepresentationFlyweightFactory::setSurfaceSubdivisionLevel(unsigned short level) {
	m_opaque_policy.setSurfaceSubdivisionLevel(level);
	m_gradient_policy.setSurfaceSubdivisionLevel(level);
}
