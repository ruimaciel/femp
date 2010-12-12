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
	this->clear();
}


void SceneGraph::clear()
{
	mylog.setPrefix("void SceneGraph::clear()");
	mylog.message("must implement this");

	//TODO finish this

	// frees the primitives included in the list
	for(std::list<SceneGraphComponent *>::iterator i = primitive_components.begin(); i != primitive_components.end(); i++)
	{
		delete(*i);
	}
}


void SceneGraph::paint(ModelViewport *mvp)
{
	using namespace std;
	// get the model
	glGetFloatv(GL_PROJECTION_MATRIX, mvp->viewport_data.modelview) ;

	this->paintGL(mvp->viewport_data, mvp->model, mvp->colors);
}


void SceneGraph::addPrimitiveComponent(SceneGraphComponent *new_component)
{
	assert(new_component != NULL);
	this->primitive_components.push_back(new_component);
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


