#include "SceneGraphComponent.h++"



fem::Model * SceneGraphComponent::model = NULL;


SceneGraphComponent::SceneGraphComponent()
{
}


SceneGraphComponent::~SceneGraphComponent()
{
	for(std::list<SceneGraphComponent *>::iterator i = children.begin(); i!= children.end(); i++)
	{
		delete *i;
	}

	delete boundary;
}


void SceneGraphComponent::paintGL()
{
	for(std::list<SceneGraphComponent *>::iterator i = this->children.begin(); i != this->children.end(); i++)
	{
		(*i)->paintGL();
	}
}


void SceneGraphComponent::pushComponent(SceneGraphComponent &new_component)
{
	SceneGraphComponent *c = new SceneGraphComponent;

	// initialize the new object
	c->children = new_component.children;
	c->boundary = new_component.boundary;

	this->children.push_back(c);
}


