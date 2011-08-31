#include "ElementFactory.h++"

#include "SceneGraphException.h++"

#include "Elements/Tetrahedron4.h++"
#include "Elements/Tetrahedron10.h++"


namespace SGC	// namespace for all scene graph components
{

Element *
ElementFactory::operator() (fem::Element &element)
{
	Element *scene_graph_element;
	switch(element.type)
	{
		case fem::Element::FE_TETRAHEDRON4:
			scene_graph_element = new Tetrahedron4(element);
			break;

		case fem::Element::FE_TETRAHEDRON10:
			scene_graph_element = new Tetrahedron10(element);
			break;

		default:
			throw SceneGraphException("unknown element type request");
			return NULL;
			break;
	}

	return scene_graph_element;
}

}


