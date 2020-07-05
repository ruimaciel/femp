#ifndef SCENE_GRAPH_COMPONENT_SCENE_COMPONENT_FACTORY_HPP
#define SCENE_GRAPH_COMPONENT_SCENE_COMPONENT_FACTORY_HPP

#include "SGCElement.h++"
#include <libfemp/Element.h++>

class ElementRepresentationPolicy;
class DisplacementsRepresentationPolicy;

namespace SGC // namespace for all scene graph components
{

/**
 * Defines a factory class which creates objects of type Element given an object of type fem::Element
**/
class SceneComponentFactory {
public:
    virtual ~SceneComponentFactory();

    void setElementRepresentationPolicy(ElementRepresentationPolicy* representation);
    void setDisplacementsPolicy(DisplacementsRepresentationPolicy* displacements);

    /**
     * Factory method
    **/
    virtual Element* operator()(fem::element_ref_t const&, fem::Element& element);

protected:
    ElementRepresentationPolicy* m_representation;
    DisplacementsRepresentationPolicy* m_displacement;
};

}

#endif
