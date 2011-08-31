#include "SGCElement.h++"

#include <assert.h>


namespace SGC	// namespace for all scene graph components
{


Element::Element(fem::Element &reference_element)
	: SceneGraphComponent()
{
	this->setReferenceElement(reference_element);
}


Element::~Element()
{
}


void 
Element::setReferenceElement(fem::Element &referenced_element)
{
	this->m_element = &referenced_element;

	//TODO adjust boundary to this surface
}


void Element::accept(OperationsVisitor &v)
{
	v.visit(*this);
}

}
