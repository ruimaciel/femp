#include "SceneGraph.h++"

#include <assert.h>
#include <iostream>

#include "Logs.h++"

#include "ModelViewport.h++"


SceneGraph::RenderGroup::RenderGroup()
{
	this->render = true;
	this->selectable = true;
}


void SceneGraph::RenderGroup::generateSceneGraph()
{
	//TODO implement a better scenegraph structure

	for(std::list<SceneGraphComponent *>::iterator i = this->primitive_components.begin(); i != this->primitive_components.end(); i++)
	{
		this->scenegraph.pushComponent( *i );
	}
}


SceneGraph::SceneGraph()
{
}


SceneGraph::~SceneGraph()
{
	this->clear();
}


void SceneGraph::clear()
{
	using namespace std;
	//TODO finish this

	// frees the primitives included in the list
	for(map<int, RenderGroup>::iterator i = rendering_groups.begin(); i != rendering_groups.end(); i++)
	{
		for(std::list<SceneGraphComponent *>::iterator j = i->second.primitive_components.begin(); j != i->second.primitive_components.end(); j++)
		{
			delete(*j);
		}
	}
}


void SceneGraph::paint(ViewportData &viewport_data, fem::Model &model, ViewportColors &colors)
{
	using namespace std;
	// get the model
	glGetFloatv(GL_PROJECTION_MATRIX, viewport_data.modelview) ;

	for(map<int, RenderGroup>::iterator i = rendering_groups.begin(); i != rendering_groups.end(); i++)
	{
		if(i->second.render)
			i->second.scenegraph.paintGL(viewport_data, &model, colors);
	}
}


void SceneGraph::addPrimitiveComponent(int group, SceneGraphComponent *new_component)
{
	assert(new_component != NULL);
	//this->primitive_components.push_back(new_component);
	rendering_groups[group].primitive_components.push_back(new_component);
}


void SceneGraph::generateSceneGraph()
{
	for(std::map<int, RenderGroup>::iterator i = this->rendering_groups.begin(); i!= this->rendering_groups.end(); i++)
	{
		i->second.generateSceneGraph();
	}
}


