#ifndef SGC_ELEMENT_HEXAHEDRON20_HPP
#define SGC_ELEMENT_HEXAHEDRON20_HPP

#include "../DisplacementsRepresentationPolicy/DisplacementsRepresentationPolicy.hpp"
#include "../ElementRepresentationPolicy/ElementRepresentationPolicy.hpp"
#include "../SGCElement.hpp"

namespace SGC  // namespace for all scene graph components
{

/**
Base class for a  all scene graph components that represent a 20-node hexahedron
**/
class Hexahedron20 : public Element {
	public:
	/*
		@param	reference_element	the reference to this element's fem::Element
	   object
		*/
	Hexahedron20(fem::element_ref_t const&, fem::Element& reference_element, ElementRepresentationPolicy* representation,
				 DisplacementsRepresentationPolicy* displacements);

	protected:
	void paintGL(ViewportData& data, ViewportColors& colors) override;
};
}  // namespace SGC

#endif
