#ifndef FEMP_VIEWER_SGC_HEXAHEDRON27_HPP
#define FEMP_VIEWER_SGC_HEXAHEDRON27_HPP

#include "../DisplacementsRepresentationPolicy/DisplacementsRepresentationPolicy.hpp"
#include "../ElementRepresentationPolicy/ElementRepresentationPolicy.hpp"
#include "../SGCElement.hpp"

namespace SGC  // namespace for all scene graph components
{

/**
Base class for a  all scene graph components that represent a 27-node hexahedron
**/
class Hexahedron27 : public Element {
	public:
	/*
		@param	reference_element	the reference to this element's fem::Element
	   object
		*/
	Hexahedron27(fem::element_ref_t const&, fem::Element& reference_element, ElementRepresentationPolicy* representation,
				 DisplacementsRepresentationPolicy* displacements);

	protected:
	void paintGL(ViewportData& data, ViewportColors& colors) override;
};
}  // namespace SGC

#endif
