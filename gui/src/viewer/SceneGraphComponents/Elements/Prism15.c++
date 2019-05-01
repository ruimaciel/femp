#include "Prism15.h++"


namespace SGC	// namespace for all scene graph components
{

Prism15::Prism15(fem::element_ref_t const &ref,fem::Element &reference_element, ElementRepresentationPolicy *representation, DisplacementsRepresentationPolicy *displacements)
    : Element(ref ,reference_element, representation, displacements)
{
}


void
Prism15::paintGL(ViewportData &, ViewportColors &colors)
{
    assert(m_element != nullptr);
    assert(m_element->type == fem::Element::FE_PRISM15);
    assert(m_representation != nullptr);
    assert(m_displacements != nullptr);

    m_representation->prism15(m_element_reference, *m_element, colors, m_displacements);
}


}
