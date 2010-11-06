#include "SceneGraphComponent.h++"


#include <assert.h>
#include "Logs.h++"	// declare the global message loggers



SceneGraphComponent::SceneGraphComponent()
{
}


SceneGraphComponent::~SceneGraphComponent()
{
	//TODO implement a better cleanup code
	/*
	for(std::list<SceneGraphComponent *>::iterator i = children.begin(); i!= children.end(); i++)
	{
		delete *i;
	}

	delete boundary;
	*/
}


void SceneGraphComponent::paintGL(ViewportData &data, fem::Model *model, ViewportColors &colors)
{
	mylog.setPrefix("void SceneGraphComponent::paintGL()");
	mylog.message("painting");
	for(std::list<SceneGraphComponent *>::iterator i = this->children.begin(); i != this->children.end(); i++)
	{
		(*i)->paintGL(data, model, colors);
	}
}


void SceneGraphComponent::pushComponent(SceneGraphComponent *new_component)
{
	assert(new_component != NULL);

	/*
	SceneGraphComponent *c = new SceneGraphComponent;

	// initialize the new object
	c->children 	= new_component->children;
	c->boundary 	= new_component->boundary;
	*/

	this->children.push_back(new_component);
}


