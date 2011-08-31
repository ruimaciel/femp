#include "SceneGraphComponent.h++"


#include <assert.h>
#include "../Logs.h++"	// declare the global message loggers



SceneGraphComponent::SceneGraphComponent()
{
	selected = false;
}


SceneGraphComponent::~SceneGraphComponent()
{
	//TODO implement a better cleanup code
}


void SceneGraphComponent::paintGL(ViewportData &data, ViewportColors &colors)
{
	for(std::list<SceneGraphComponent *>::iterator i = this->children.begin(); i != this->children.end(); i++)
	{
		(*i)->paintGL(data, colors);
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


void SceneGraphComponent::accept(OperationsVisitor &)
{
	mylog.setPrefix("void SceneGraphComponent::Accept(OperationsVisitor &v)");
	mylog.message("error: base class element being called");
}
