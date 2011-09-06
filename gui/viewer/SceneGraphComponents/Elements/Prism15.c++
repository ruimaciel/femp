#include "Prism15.h++"


namespace SGC	// namespace for all scene graph components
{

Prism15::Prism15(fem::Element &reference_element, ElementRepresentationPolicy *representation, DisplacementsRepresentationPolicy *displacements)
	: Element(reference_element, representation, displacements)
{
}


void 
Prism15::paintGL(ViewportData &, ViewportColors &colors)
{
	assert(m_element != NULL);
	assert(m_element->type == fem::Element::FE_PRISM15);
	assert(m_representation != NULL);
	assert(m_displacements != NULL);

	m_representation->prism15(*m_element, colors, m_displacements);
}



}
