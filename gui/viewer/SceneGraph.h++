#ifndef SCENE_GRAPH_HPP
#define SCENE_GRAPH_HPP

#include <sigc++/sigc++.h> 	// to side step a compiler error caused by a conflict with Qt and libsigc++
#include <list>
#include <map>

#include <GL/gl.h>

#include "SceneGraphComponents/SceneGraphComponent.h++"
#include "SceneGraphComponents/hud/HudSelection.h++"

#include "ViewportData.h++"
#include "ViewportColors.h++"
#include "../Project.h++"
#include "RenderGroup.h++"


/*
Facade pattern for the scenegraph structure
*/
class SceneGraph
{
public:
	enum Groups 	// common groups for all scenegraphs
	{
		RG_NODES,	// the element nodes
		RG_SURFACES,	// the opaque surfaces used in ModelViewport an DisplacementsViewport
		RG_WIREFRAME,	// wireframe of the opaque surfaces.  This group and RG_SURFACES are mutually explusive
		RG_GHOST_SURFACES,	// surfaces rendered in the displacement viewport to show the model's original configuration
		RG_NODE_RESTRICTIONS
	};

public:
	/* 
	This is the master list of all scene graph objects in this scene graph.
	It is used to store every object of type SGCSurface (etc...) managed by this scenegraph.
	*/
	std::list<SceneGraphComponent *> primitive_components;

	std::map<enum Groups, RenderGroup>	rendering_groups;

	hud::Selection	m_selection;	// HUD object to render selection

public:
	SceneGraph();
	~SceneGraph();


	/*
	Clears all the data structures managed by this class
	*/
	void clear();


	void paint(ViewportData &viewport_data, ViewportColors &colors);

	/**
	Generates all the display lists
	**/
	void generateDisplayLists(ViewportData &viewport_data, ViewportColors &colors);

	/**
	Renders the openGL scene, which consists of the list of display lists and 2D elements
	**/
	// void paintGL();

	/*
	Generic routine to add a primitive component to this scenegraph
	The template was provided for syntax convenience only; this class only accepts specific types derived from SceneGraphComponent
	@param group	destination RenderGroup
	@param *newcomponent	new scenegraph component
	*/
	void addPrimitiveComponent(enum Groups group, SceneGraphComponent *new_component);

	/*
	Generate a new scenegraph tree from the current list of primitive components
	*/
	void generateSceneGraph();

	/** 
	visitor pattern for the scenegraph
	@param	visitor	class which will act on each object 
	**/
	void runOperation(Operation::OperationsVisitor &);


	void setSelectionStart(fem::Point const &p)	{ m_selection.setStart(p); };
	void setSelectionEnd(fem::Point const &p)	{ m_selection.setEnd(p); };
	void setSelectionOff()				{ m_selection.off(); };
};

#endif
