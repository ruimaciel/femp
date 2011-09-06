#include "Prism6.h++"


namespace SGC	// namespace for all scene graph components
{

Prism6::Prism6(fem::Element &reference_element, ElementRepresentationPolicy *representation, DisplacementsRepresentationPolicy *displacements)
	: Element(reference_element, representation, displacements)
{
}


void 
Prism6::paintGL(ViewportData &, ViewportColors &colors)
{
	assert(m_element != NULL);
	assert(m_element->type == fem::Element::FE_PRISM6);
	assert(m_representation != NULL);
	assert(m_displacements != NULL);

	m_representation->prism6(*m_element, colors, m_displacements);
}



}
