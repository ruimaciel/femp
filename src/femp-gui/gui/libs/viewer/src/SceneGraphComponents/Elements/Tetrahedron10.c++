#include "Tetrahedron10.h++"

namespace SGC  // namespace for all scene graph components
{

Tetrahedron10::Tetrahedron10(fem::element_ref_t const& ref, fem::Element& reference_element, ElementRepresentationPolicy* representation,
							 DisplacementsRepresentationPolicy* displacements)
	: Element(ref, reference_element, representation, displacements) {}

void Tetrahedron10::paintGL(ViewportData&, ViewportColors& colors) {
	assert(m_element != nullptr);
	assert(m_element->getType() == fem::Element::FE_TETRAHEDRON10);
	assert(m_representation != nullptr);
	assert(m_displacements != nullptr);

	m_representation->tetra10(m_element_reference, *m_element, colors, m_displacements);
}
}  // namespace SGC
