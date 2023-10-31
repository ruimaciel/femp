#include "SGCElement.h++"

#include <assert.h>

#include "DisplacementsRepresentationPolicy/DisplacementsRepresentationPolicy.h++"
#include "ElementRepresentationPolicy/ElementRepresentationPolicy.h++"

namespace SGC  // namespace for all scene graph components
{

Element::Element(fem::element_ref_t const& ref, fem::Element& reference_element, ElementRepresentationPolicy* representation,
				 DisplacementsRepresentationPolicy* displacements)
	: SceneGraphComponent() {
	this->setReferenceElement(ref, reference_element);
	this->setElementRepresentationPolicy(representation);
	this->setDisplacementsPolicy(displacements);
}

fem::element_ref_t Element::reference() const {
	return m_element_reference;
}

void Element::setElementRepresentationPolicy(ElementRepresentationPolicy* representation) {
	assert(representation != nullptr);
	this->m_representation = representation;
}

void Element::setDisplacementsPolicy(DisplacementsRepresentationPolicy* displacements) {
	assert(displacements != nullptr);
	this->m_displacements = displacements;
}

void Element::accept(Operation::OperationsVisitor& visitor) {
	visitor.visit(*this);
}

void Element::setReferenceElement(fem::element_ref_t const& ref, fem::Element& referenced_element) {
	this->m_element_reference = ref;
	this->m_element = &referenced_element;
}

}  // namespace SGC
