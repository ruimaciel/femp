#ifndef SCENE_GRAPH_COMPONENT_HPP
#define SCENE_GRAPH_COMPONENT_HPP


#include <list>

#include "boundaries/BoundaryStrategy.h++"	// a definition of a bounding volume through the use of a strategy pattern

#include "../fem/Model.h++"



/*
Component class which is used to implement a bounding volume hierarchy for the scene graph through a composit design pattern
**/
class SceneGraphComponent
{
	protected:
		std::list<SceneGraphComponent *> children;	// list of all child objects which are a part of the composition
		BoundaryStrategy *boundary;	// a boundary volume which contains this component

		static float detail_factor;	// test value which is used to set the detail level of the drawings
		static fem::Model *model;	// pointer to a valid model

	public:
		SceneGraphComponent();
		~SceneGraphComponent();

		static void setDetailFactor(const float & new_detail_factor) { detail_factor = new_detail_factor; }

		/*
		Render the content of this Scenegraph component
		*/
		virtual void paintGL();

		/*
		Pushes a new scenegraph component to this component's children's list
		This routine makes a copy of object new_component and adds a pointer to thew new object in the children's list
		*/
		void pushComponent(SceneGraphComponent &new_component);
};


#endif
