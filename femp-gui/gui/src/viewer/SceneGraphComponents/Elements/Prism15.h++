#ifndef SGC_ELEMENT_PRISM15_HPP
#define SGC_ELEMENT_PRISM15_HPP

#include "../SGCElement.h++"

#include "../DisplacementsRepresentationPolicy/DisplacementsRepresentationPolicy.h++"
#include "../ElementRepresentationPolicy/ElementRepresentationPolicy.h++"

namespace SGC // namespace for all scene graph components
{

/**
Base class for a  all scene graph components that represent a 15-node prism
**/
class Prism15
    : public Element {
public:
    /*
	@param	reference_element	the reference to this element's fem::Element object
	*/
    Prism15(fem::element_ref_t const&, fem::Element& reference_element, ElementRepresentationPolicy* representation, DisplacementsRepresentationPolicy* displacements);

protected:
    void paintGL(ViewportData& data, ViewportColors& colors);
};
}

#endif
