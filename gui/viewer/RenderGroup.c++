#include "RenderGroup.h++"


RenderGroup::RenderGroup()
{
	this->render = true;
	this->selectable = true;
}


void 
RenderGroup::generateSceneGraph()
{
	//TODO implement a better scenegraph structure

	for(std::list<SceneGraphComponent *>::iterator i = this->primitive_components.begin(); i != this->primitive_components.end(); i++)
	{
		this->scenegraph.pushComponent( *i );
	}
}

