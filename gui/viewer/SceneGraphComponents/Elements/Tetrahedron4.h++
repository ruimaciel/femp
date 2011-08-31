#ifndef SGC_ELEMENT_TETRAHEDRON4_HPP
#define SGC_ELEMENT_TETRAHEDRON4_HPP

#include "../SGCElement.h++"

#include "../ElementRepresentationPolicy/ElementRepresentationPolicy.h++"
#include "../DisplacementsRepresentationPolicy/DisplacementsRepresentationPolicy.h++"

namespace SGC	// namespace for all scene graph components
{

/**
Base class for a  all scene graph components that represent a 4-node tetrahedron
**/
class Tetrahedron4
	: public Element
{
public:
	/*
	@param	reference_element	the reference to this element's fem::Element object
	*/
	Tetrahedron4(fem::Element &reference_element);

protected:
	void paintGL(fem::Project &project, ViewportColors &colors, ElementRepresentationPolicy *representation, DisplacementsRepresentationPolicy *displacements);

};

}

#endif
