#ifndef SCENE_GRAPH_HPP
#define SCENE_GRAPH_HPP

#include <list>

#include "SceneGraphComponent.h++"

#include "../fem/Model.h++"


/*
Facade pattern for the scenegraph structure
*/
class SceneGraph
	: public SceneGraphComponent
{
	protected:
		/* 
		This is the master list of all scene graph objects in this scene graph.
		It is used to store every object of type SGCSurface (etc...) managed by this scenegraph.
		*/
		std::list<SceneGraphComponent *> primitive_components;

	public:
		SceneGraph(fem::Model &new_model);
		~SceneGraph();


		/*
		Generic routine to add a primitive component to this scenegraph
		The template was provided for syntax convenience only; this class only accepts specific types derived from SceneGraphComponent
		*/
		template<typename PrimitiveComponent>
		void addPrimitiveComponent(PrimitiveComponent &new_component);

		/*
		Generate a new scenegraph tree from the current list of primitive components
		*/
		void generateSceneGraph();
};

#endif
