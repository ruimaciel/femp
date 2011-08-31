#include "Tetrahedron10.h++"


namespace SGC	// namespace for all scene graph components
{

Tetrahedron10::Tetrahedron10(fem::Element &reference_element)
	: Element(reference_element)
{
}


void 
Tetrahedron10::paintGL(fem::Project &project, ViewportColors &colors, ElementRepresentationPolicy *representation, DisplacementsRepresentationPolicy *displacements)
{
	assert(m_element != NULL);
	assert(m_element->type == fem::Element::FE_TETRAHEDRON10);
	assert(representation != NULL);
	assert(displacements != NULL);

	representation->tetra10(*m_element, colors, displacements);
}



}
