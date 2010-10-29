#include "SceneGraph.h++"

#include <assert.h>

#include "SGCSurface.h++"


SceneGraph::SceneGraph(fem::Model &new_model)
	: SceneGraphComponent()
{
	this->model = &new_model;	// sets this scenegraph's model
}


SceneGraph::~SceneGraph()
{
}


template<typename PrimitiveComponent>
void SceneGraph::addPrimitiveComponent(PrimitiveComponent &new_component)
{
	static_assert(true,"only specialized types are allowed");
}


template<>
void SceneGraph::addPrimitiveComponent(fem::Surface &new_component)
{
	SGCSurface * new_surface = new SGCSurface;
	new_surface->setReferenceSurface(new_component);

	// add this component to the primitive components' list
	this->primitive_components.push_back(new_surface);
}


void SceneGraph::generateSceneGraph()
{
	//TODO implement a better scenegraph structure

	for(std::list<SceneGraphComponent *>::iterator i = this->primitive_components.begin(); i != this->primitive_components.end(); i++)
	{
		this->pushComponent( **i );
	}
}


