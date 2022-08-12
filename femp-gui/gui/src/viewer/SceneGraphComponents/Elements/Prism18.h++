#ifndef SGC_ELEMENT_PRISM18_HPP
#define SGC_ELEMENT_PRISM18_HPP

#include "../DisplacementsRepresentationPolicy/DisplacementsRepresentationPolicy.h++"
#include "../ElementRepresentationPolicy/ElementRepresentationPolicy.h++"
#include "../SGCElement.h++"

namespace SGC  // namespace for all scene graph components
{

/**
Base class for a  all scene graph components that represent a 18-node prism
**/
class Prism18 : public Element {
   public:
	/*
		@param	reference_element	the reference to this element's fem::Element
	   object
		*/
	Prism18(fem::element_ref_t const&, fem::Element& reference_element, ElementRepresentationPolicy* representation,
			DisplacementsRepresentationPolicy* displacements);

   protected:
	void paintGL(ViewportData& data, ViewportColors& colors);
};
}  // namespace SGC

#endif
