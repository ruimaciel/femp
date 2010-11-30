#include "SceneGraph.h++"

#include <assert.h>
#include <iostream>

#include "Logs.h++"

#include "ModelViewport.h++"


SceneGraph::SceneGraph()
	: SceneGraphComponent()
{
}


SceneGraph::~SceneGraph()
{
}


void SceneGraph::clear()
{
	mylog.setPrefix("void SceneGraph::clear()");
	mylog.message("must implement this");
}


void SceneGraph::paint(ModelViewport *mvp)
{
	using namespace std;
	// get the model
	glGetFloatv(GL_PROJECTION_MATRIX, mvp->viewport_data.modelview) ;

	this->paintGL(mvp->viewport_data, mvp->model, mvp->colors);
}


/*
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
*/


void SceneGraph::addPrimitiveComponent(SceneGraphComponent *new_component)
{
	assert(new_component != NULL);
	this->primitive_components.push_back(new_component);
}


/*
template<>
void SceneGraph::addPrimitiveComponent(fem::Node &new_component)
{
	mylog.setPrefix("void SceneGraph::addPrimitiveComponent(fem::Node &new_component)");
	mylog.message("add a node");

	SGCNode * new_node = new SGCNode;
	new_node->setReferenceNode(new_component);

	this->primitive_components.push_back(new_node);
}
*/


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


