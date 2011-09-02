#include "SceneComponentFactory.h++"

#include <assert.h>

#include "SceneGraphException.h++"

#include "Elements/Tetrahedron4.h++"
#include "Elements/Tetrahedron10.h++"
#include "Elements/Hexahedron8.h++"
#include "Elements/Hexahedron20.h++"
#include "Elements/Hexahedron27.h++"
#include "Elements/Prism6.h++"
#include "Elements/Prism15.h++"
#include "Elements/Prism18.h++"


namespace SGC	// namespace for all scene graph components
{

Element *
SceneComponentFactory::operator() (fem::Element &element)
{
	assert(this->m_representation != NULL);
	assert(this->m_displacement != NULL);

	Element *scene_graph_element;
	switch(element.type)
	{
		case fem::Element::FE_TETRAHEDRON4:
			scene_graph_element = new Tetrahedron4(element, m_representation, m_displacement);
			break;

		case fem::Element::FE_TETRAHEDRON10:
			scene_graph_element = new Tetrahedron10(element, m_representation, m_displacement);
			break;

		case fem::Element::FE_HEXAHEDRON8:
			scene_graph_element = new Hexahedron8(element, m_representation, m_displacement);
			break;

		case fem::Element::FE_HEXAHEDRON20:
			scene_graph_element = new Hexahedron20(element, m_representation, m_displacement);
			break;

		case fem::Element::FE_HEXAHEDRON27:
			scene_graph_element = new Hexahedron27(element, m_representation, m_displacement);
			break;

		case fem::Element::FE_PRISM6:
			scene_graph_element = new Prism6(element, m_representation, m_displacement);
			break;

		case fem::Element::FE_PRISM15:
			scene_graph_element = new Prism15(element, m_representation, m_displacement);
			break;

		case fem::Element::FE_PRISM18:
			scene_graph_element = new Prism18(element, m_representation, m_displacement);
			break;

		default:
			throw SceneGraphException("unknown element type request");
			return NULL;
			break;
	}

	return scene_graph_element;
}


void 
SceneComponentFactory::setElementRepresentationPolicy(ElementRepresentationPolicy *representation)
{
	assert(representation != NULL);
	this->m_representation = representation;
}


void 
SceneComponentFactory::setDisplacementsPolicy(DisplacementsRepresentationPolicy *displacements)
{
	assert(displacements != NULL);
	this->m_displacement = displacements;
}



}


