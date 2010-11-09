#include "SceneGraph.h++"

#include <assert.h>

#include "SGCNode.h++"
#include "SGCSurface.h++"

#include "Logs.h++"


SceneGraph::SceneGraph()
	: SceneGraphComponent()
{
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
	mylog.setPrefix("void SceneGraph::addPrimitiveComponent(fem::Surface &new_component)");
	mylog.message("add a surface");

	SGCSurface * new_surface = new SGCSurface;
	new_surface->setReferenceSurface(new_component);

	// add this component to the primitive components' list
	this->primitive_components.push_back(new_surface);
}


template<>
void SceneGraph::addPrimitiveComponent(fem::Node &new_component)
{
	mylog.setPrefix("void SceneGraph::addPrimitiveComponent(fem::Node &new_component)");
	mylog.message("add a node");

	SGCNode * new_node = new SGCNode;
	new_node->setReferenceNode(new_component);

	this->primitive_components.push_back(new_node);
}


void SceneGraph::generateSceneGraph()
{
	mylog.setPrefix(" void SceneGraph::generateSceneGraph()");
	mylog.message("generating scene graph");

	//TODO implement a better scenegraph structure

	for(std::list<SceneGraphComponent *>::iterator i = this->primitive_components.begin(); i != this->primitive_components.end(); i++)
	{
		this->pushComponent( *i );
	}
}


