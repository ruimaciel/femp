#include "RenderGroup.h++"


RenderGroup::RenderGroup()
{
	this->render = true;
	this->selectable = true;

	//display_list = glGenLists(1);
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


void 
RenderGroup::generateDisplayList( ViewportData & /*data*/, ViewportColors & /*colors*/)
{
	//TODO generate display list
	/*
	glNewList(display_list, GL_COMPILE_AND_EXECUTE);
	this->scenegraph.paintGL(data, colors);
	glEndList();
	*/
}


void 
RenderGroup::paintGL()
{
	/*
	glCallList(display_list);
	glFlush();
	*/
}

