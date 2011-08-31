#include "Tetrahedron4.h++"


namespace SGC	// namespace for all scene graph components
{

Tetrahedron4::Tetrahedron4(fem::Element &reference_element)
	: Element(reference_element)
{
}


void 
Tetrahedron4::paintGL(fem::Project &project, ViewportColors &colors, ElementRepresentationPolicy *representation, DisplacementsRepresentationPolicy *displacements)
{
	assert(m_element != NULL);
	assert(m_element->type == fem::Element::FE_TETRAHEDRON4);
	assert(representation != NULL);
	assert(displacements != NULL);

	representation->tetra4(*m_element, colors, displacements);
}



}
