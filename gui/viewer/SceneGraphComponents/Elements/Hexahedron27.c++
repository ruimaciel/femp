#include "Hexahedron27.h++"


namespace SGC	// namespace for all scene graph components
{

Hexahedron27::Hexahedron27(fem::element_ref_t const &ref,fem::Element &reference_element, ElementRepresentationPolicy *representation, DisplacementsRepresentationPolicy *displacements)
	: Element(ref ,reference_element, representation, displacements)
{
}


void 
Hexahedron27::paintGL(ViewportData &, ViewportColors &colors)
{
	assert(m_element != NULL);
	assert(m_element->type == fem::Element::FE_HEXAHEDRON27);
	assert(m_representation != NULL);
	assert(m_displacements != NULL);

	m_representation->hexa27(m_element_reference, *m_element, colors, m_displacements);
}


}
