#ifndef SCENE_GRAPH_COMPONENT_ELEMENT_FACTORY_HPP
#define SCENE_GRAPH_COMPONENT_ELEMENT_FACTORY_HPP


#include "SGCElement.h++"
#include "../../fem/Element.h++"


namespace SGC	// namespace for all scene graph components
{

/**
Defines a factory class which creates objects of type Element given an object of type fem::Element
**/
class ElementFactory
{
public:
	
	/**
	Factory method
	**/
	virtual Element * operator() (fem::Element &element);

};

}

#endif
