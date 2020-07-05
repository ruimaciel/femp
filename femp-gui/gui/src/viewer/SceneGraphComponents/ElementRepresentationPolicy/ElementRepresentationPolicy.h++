
#ifndef ELEMENTREPRESENTATIONPOLICY_H
#define ELEMENTREPRESENTATIONPOLICY_H

#include "../DisplacementsRepresentationPolicy/DisplacementsRepresentationPolicy.h++"
#include <libfemp/Element.h++>
#include <options/Options.h++>

/**
 * Defines a policy to represent elements according to specific criteria.
 * Each member function runs a set of OpenGL commands.
**/
class ElementRepresentationPolicy {
protected:
    DisplacementsRepresentationPolicy* m_displacement;
    unsigned short m_surface_subdivision_level;

public:
    ElementRepresentationPolicy();
    virtual ~ElementRepresentationPolicy();

    void setDisplacementPolicy(DisplacementsRepresentationPolicy* displacement);

    virtual void tetra4(fem::element_ref_t const&, fem::Element& element, ViewportColors& color, DisplacementsRepresentationPolicy* displacement) = 0;
    virtual void tetra10(fem::element_ref_t const&, fem::Element& element, ViewportColors& color, DisplacementsRepresentationPolicy* displacement) = 0;
    virtual void hexa8(fem::element_ref_t const&, fem::Element& element, ViewportColors& color, DisplacementsRepresentationPolicy* displacement) = 0;
    virtual void hexa20(fem::element_ref_t const&, fem::Element& element, ViewportColors& color, DisplacementsRepresentationPolicy* displacement) = 0;
    virtual void hexa27(fem::element_ref_t const&, fem::Element& element, ViewportColors& color, DisplacementsRepresentationPolicy* displacement) = 0;
    virtual void prism6(fem::element_ref_t const&, fem::Element& element, ViewportColors& color, DisplacementsRepresentationPolicy* displacement) = 0;
    virtual void prism15(fem::element_ref_t const&, fem::Element& element, ViewportColors& color, DisplacementsRepresentationPolicy* displacement) = 0;
    virtual void prism18(fem::element_ref_t const&, fem::Element& element, ViewportColors& color, DisplacementsRepresentationPolicy* displacement) = 0;

    void setSurfaceSubdivisionLevel(unsigned short level) { m_surface_subdivision_level = level; }
};

#endif // ELEMENTREPRESENTATIONPOLICY_H
