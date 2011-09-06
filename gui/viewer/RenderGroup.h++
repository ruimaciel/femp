#ifndef RENDER_GROUP_HPP
#define RENDER_GROUP_HPP

#include <GL/gl.h>
#include <list>

#include "SceneGraphComponents/SceneGraphComponent.h++"


/**
Definition of a render group: an independent scene graph branch 
**/
struct RenderGroup
{

	bool render;	// should this group be rendered?
	bool selectable;	// are the elements in this group selectable?
	GLuint display_list;

	std::list<SceneGraphComponent *> primitive_components;	// list of primitive components included in this group

	SceneGraphComponent scenegraph;

	RenderGroup();

	/*
	   Generate a new scenegraph tree from the current list of primitive components
	*/
	void generateSceneGraph();
};

#endif
