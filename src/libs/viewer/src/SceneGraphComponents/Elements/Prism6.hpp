#ifndef FEMP_VIEWER_SGC_PRISM6_HPP
#define FEMP_VIEWER_SGC_PRISM6_HPP

#include "../DisplacementsRepresentationPolicy/DisplacementsRepresentationPolicy.hpp"
#include "../ElementRepresentationPolicy/ElementRepresentationPolicy.hpp"
#include "../SGCElement.hpp"

namespace SGC  // namespace for all scene graph components
{

/**
Base class for a  all scene graph components that represent a 6-node prism
**/
class Prism6 : public Element {
	public:
	/*
		@param	reference_element	the reference to this element's fem::Element
	   object
		*/
	Prism6(fem::element_ref_t const&, fem::Element& reference_element, ElementRepresentationPolicy* representation,
		   DisplacementsRepresentationPolicy* displacements);

	protected:
	void paintGL(ViewportData& data, ViewportColors& colors) override;
};
}  // namespace SGC

#endif
