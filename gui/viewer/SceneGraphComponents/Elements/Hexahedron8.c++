#include "Hexahedron8.h++"


namespace SGC	// namespace for all scene graph components
{

Hexahedron8::Hexahedron8(fem::Element &reference_element, ElementRepresentationPolicy *representation, DisplacementsRepresentationPolicy *displacements)
	: Element(reference_element, representation, displacements)
{
}


void 
Hexahedron8::paintGL(ViewportData &data, ViewportColors &colors)
{
	assert(m_element != NULL);
	assert(m_element->type == fem::Element::FE_HEXAHEDRON8);
	assert(m_representation != NULL);
	assert(m_displacements != NULL);

	m_representation->hexa8(*m_element, colors, m_displacements);
}



}
