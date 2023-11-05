#ifndef FEMP_VIEWER_SGC_TETRAHEDRON10_HPP
#define FEMP_VIEWER_SGC_TETRAHEDRON10_HPP

#include "../DisplacementsRepresentationPolicy/DisplacementsRepresentationPolicy.hpp"
#include "../ElementRepresentationPolicy/ElementRepresentationPolicy.hpp"
#include "../SGCElement.hpp"

namespace SGC  // namespace for all scene graph components
{

/**
Base class for a  all scene graph components that represent a 4-node tetrahedron
**/
class Tetrahedron10 : public Element {
	public:
	/*
		@param	reference_element	the reference to this element's fem::Element
	   object
		*/
	Tetrahedron10(fem::element_ref_t const&, fem::Element& reference_element, ElementRepresentationPolicy* representation,
				  DisplacementsRepresentationPolicy* displacements);

	protected:
	void paintGL(ViewportData& data, ViewportColors& colors) override;
};
}  // namespace SGC

#endif
