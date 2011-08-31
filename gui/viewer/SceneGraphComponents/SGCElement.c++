#include "SGCElement.h++"

#include <assert.h>


namespace SGC	// namespace for all scene graph components
{


Element::Element(fem::Element &reference_element, ElementRepresentationPolicy *representation, DisplacementsRepresentationPolicy *displacements)
	: SceneGraphComponent()
{
	this->setReferenceElement(reference_element);
	this->setElementRepresentationPolicy(representation);
	this->setDisplacementsPolicy(displacements);
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


void 
Element::setElementRepresentationPolicy(ElementRepresentationPolicy *representation)
{
	assert(representation != NULL);
	this->m_representation = representation;
}


void 
Element::setDisplacementsPolicy(DisplacementsRepresentationPolicy *displacements)
{
	assert(displacements != NULL);
	this->m_displacements = displacements;
}


void Element::accept(OperationsVisitor &v)
{
	v.visit(*this);
}

}
