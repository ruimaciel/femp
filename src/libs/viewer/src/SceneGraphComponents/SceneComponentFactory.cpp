#include "SceneComponentFactory.hpp"

#include <assert.h>

#include "DisplacementsRepresentationPolicy/DisplacementsRepresentationPolicy.hpp"
#include "ElementRepresentationPolicy/ElementRepresentationPolicy.hpp"
#include "Elements/Hexahedron20.hpp"
#include "Elements/Hexahedron27.hpp"
#include "Elements/Hexahedron8.hpp"
#include "Elements/Prism15.hpp"
#include "Elements/Prism18.hpp"
#include "Elements/Prism6.hpp"
#include "Elements/Tetrahedron10.hpp"
#include "Elements/Tetrahedron4.hpp"
#include "SceneGraphException.hpp"

namespace SGC  // namespace for all scene graph components
{

std::shared_ptr<Element> SceneComponentFactory::operator()(fem::element_ref_t const& ref, fem::Element& element) {
	assert(this->m_representation != nullptr);
	assert(this->m_displacement != nullptr);

	std::shared_ptr<Element> scene_graph_element;
	switch (element.getType()) {
		case fem::Element::FE_TETRAHEDRON4:
			scene_graph_element = std::make_shared<Tetrahedron4>(ref, element, m_representation, m_displacement);
			break;

		case fem::Element::FE_TETRAHEDRON10:
			scene_graph_element = std::make_shared<Tetrahedron10>(ref, element, m_representation, m_displacement);
			break;

		case fem::Element::FE_HEXAHEDRON8:
			scene_graph_element = std::make_shared<Hexahedron8>(ref, element, m_representation, m_displacement);
			break;

		case fem::Element::FE_HEXAHEDRON20:
			scene_graph_element = std::make_shared<Hexahedron20>(ref, element, m_representation, m_displacement);
			break;

		case fem::Element::FE_HEXAHEDRON27:
			scene_graph_element = std::make_shared<Hexahedron27>(ref, element, m_representation, m_displacement);
			break;

		case fem::Element::FE_PRISM6:
			scene_graph_element = std::make_shared<Prism6>(ref, element, m_representation, m_displacement);
			break;

		case fem::Element::FE_PRISM15:
			scene_graph_element = std::make_shared<Prism15>(ref, element, m_representation, m_displacement);
			break;

		case fem::Element::FE_PRISM18:
			scene_graph_element = std::make_shared<Prism18>(ref, element, m_representation, m_displacement);
			break;

		default:
			throw SceneGraphException("unknown element type request");
			return nullptr;
			break;
	}

	return scene_graph_element;
}

SceneComponentFactory::~SceneComponentFactory() {}

void SceneComponentFactory::setElementRepresentationPolicy(ElementRepresentationPolicy* representation) {
	assert(representation != nullptr);
	this->m_representation = representation;
}

void SceneComponentFactory::setDisplacementsPolicy(DisplacementsRepresentationPolicy* displacements) {
	assert(displacements != nullptr);
	this->m_displacement = displacements;
}
}  // namespace SGC
