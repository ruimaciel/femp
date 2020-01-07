#include "SceneComponentFactory.h++"

#include <assert.h>

#include "SceneGraphException.h++"

#include "DisplacementsRepresentationPolicy/DisplacementsRepresentationPolicy.h++"
#include "ElementRepresentationPolicy/ElementRepresentationPolicy.h++"

#include "Elements/Hexahedron20.h++"
#include "Elements/Hexahedron27.h++"
#include "Elements/Hexahedron8.h++"
#include "Elements/Prism15.h++"
#include "Elements/Prism18.h++"
#include "Elements/Prism6.h++"
#include "Elements/Tetrahedron10.h++"
#include "Elements/Tetrahedron4.h++"

namespace SGC // namespace for all scene graph components
{

Element*
SceneComponentFactory::operator()(fem::element_ref_t const& ref, fem::Element& element)
{
    assert(this->m_representation != nullptr);
    assert(this->m_displacement != nullptr);

    Element* scene_graph_element;
    switch (element.getType()) {
    case fem::Element::FE_TETRAHEDRON4:
        scene_graph_element = new Tetrahedron4(ref, element, m_representation, m_displacement);
        break;

    case fem::Element::FE_TETRAHEDRON10:
        scene_graph_element = new Tetrahedron10(ref, element, m_representation, m_displacement);
        break;

    case fem::Element::FE_HEXAHEDRON8:
        scene_graph_element = new Hexahedron8(ref, element, m_representation, m_displacement);
        break;

    case fem::Element::FE_HEXAHEDRON20:
        scene_graph_element = new Hexahedron20(ref, element, m_representation, m_displacement);
        break;

    case fem::Element::FE_HEXAHEDRON27:
        scene_graph_element = new Hexahedron27(ref, element, m_representation, m_displacement);
        break;

    case fem::Element::FE_PRISM6:
        scene_graph_element = new Prism6(ref, element, m_representation, m_displacement);
        break;

    case fem::Element::FE_PRISM15:
        scene_graph_element = new Prism15(ref, element, m_representation, m_displacement);
        break;

    case fem::Element::FE_PRISM18:
        scene_graph_element = new Prism18(ref, element, m_representation, m_displacement);
        break;

    default:
        throw SceneGraphException("unknown element type request");
        return nullptr;
        break;
    }

    return scene_graph_element;
}

SceneComponentFactory::~SceneComponentFactory()
{
}

void SceneComponentFactory::setElementRepresentationPolicy(ElementRepresentationPolicy* representation)
{
    assert(representation != nullptr);
    this->m_representation = representation;
}

void SceneComponentFactory::setDisplacementsPolicy(DisplacementsRepresentationPolicy* displacements)
{
    assert(displacements != nullptr);
    this->m_displacement = displacements;
}

}
