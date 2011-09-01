#ifndef SCENE_GRAPH_COMPONENT_SCENE_COMPONENT_FACTORY_HPP
#define SCENE_GRAPH_COMPONENT_SCENE_COMPONENT_FACTORY_HPP


#include "SGCElement.h++"
#include "../../fem/Element.h++"

#include "ElementRepresentationPolicy/ElementRepresentationPolicy.h++"
#include "DisplacementsRepresentationPolicy/DisplacementsRepresentationPolicy.h++"

namespace SGC	// namespace for all scene graph components
{

/**
Defines a factory class which creates objects of type Element given an object of type fem::Element
**/
class SceneComponentFactory
{
protected:
	ElementRepresentationPolicy *m_representation;
	DisplacementsRepresentationPolicy *m_displacement;
	
public:
	void setElementRepresentationPolicy(ElementRepresentationPolicy *representation);
	void setDisplacementsPolicy(DisplacementsRepresentationPolicy *displacements);
	
	/**
	Factory method
	**/
	virtual Element * operator() (fem::Element &element);

};

}

#endif
