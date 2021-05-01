#ifndef SGC_ELEMENT_HEXAHEDRON8_HPP
#define SGC_ELEMENT_HEXAHEDRON8_HPP

#include "../SGCElement.h++"

#include "../DisplacementsRepresentationPolicy/DisplacementsRepresentationPolicy.h++"
#include "../ElementRepresentationPolicy/ElementRepresentationPolicy.h++"

namespace SGC // namespace for all scene graph components
{

/**
Base class for a  all scene graph components that represent a 8-node hexahedron
**/
class Hexahedron8
    : public Element {
public:
    /*
	@param	reference_element	the reference to this element's fem::Element object
	*/
    Hexahedron8(fem::element_ref_t const&, fem::Element& reference_element, ElementRepresentationPolicy* representation, DisplacementsRepresentationPolicy* displacements);

protected:
    void paintGL(ViewportData& data, ViewportColors& colors);
};
}

#endif
