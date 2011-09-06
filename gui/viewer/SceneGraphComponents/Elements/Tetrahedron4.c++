#include "Tetrahedron4.h++"


namespace SGC	// namespace for all scene graph components
{

Tetrahedron4::Tetrahedron4(fem::Element &reference_element, ElementRepresentationPolicy *representation, DisplacementsRepresentationPolicy *displacements)
	: Element(reference_element, representation, displacements)
{
}


void 
Tetrahedron4::paintGL(ViewportData &, ViewportColors &colors)
{
	assert(m_element != NULL);
	assert(m_element->type == fem::Element::FE_TETRAHEDRON4);
	assert(m_representation != NULL);
	assert(m_displacements != NULL);

	m_representation->tetra4(*m_element, colors, m_displacements);
}



}
