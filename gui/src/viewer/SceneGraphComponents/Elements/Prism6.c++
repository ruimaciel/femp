#include "Prism6.h++"

namespace SGC // namespace for all scene graph components
{

Prism6::Prism6(fem::element_ref_t const& ref, fem::Element& reference_element, ElementRepresentationPolicy* representation, DisplacementsRepresentationPolicy* displacements)
    : Element(ref, reference_element, representation, displacements)
{
}

void Prism6::paintGL(ViewportData&, ViewportColors& colors)
{
    assert(m_element != nullptr);
    assert(m_element->type == fem::Element::FE_PRISM6);
    assert(m_representation != nullptr);
    assert(m_displacements != nullptr);

    m_representation->prism6(m_element_reference, *m_element, colors, m_displacements);
}

}
