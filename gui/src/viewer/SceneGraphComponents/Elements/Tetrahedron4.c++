#include "Tetrahedron4.h++"


namespace SGC	// namespace for all scene graph components
{

Tetrahedron4::Tetrahedron4(fem::element_ref_t const &ref, fem::Element &reference_element, ElementRepresentationPolicy *representation, DisplacementsRepresentationPolicy *displacements)
    : Element(ref ,reference_element, representation, displacements)
{
}


void
Tetrahedron4::paintGL(ViewportData &, ViewportColors &colors)
{
    assert(m_element != nullptr);
    assert(m_element->type == fem::Element::FE_TETRAHEDRON4);
    assert(m_representation != nullptr);
    assert(m_displacements != nullptr);

    m_representation->tetra4(m_element_reference, *m_element, colors, m_displacements);
}


}
