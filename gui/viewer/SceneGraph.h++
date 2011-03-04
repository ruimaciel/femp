#ifndef SCENE_GRAPH_HPP
#define SCENE_GRAPH_HPP

#include <list>
#include <map>

#include <GL/gl.h>

#include "SceneGraphComponents/SceneGraphComponent.h++"

#include "ViewportData.h++"
#include "ViewportColors.h++"
#include "../fem/Model.h++"


/*
Facade pattern for the scenegraph structure
*/
class SceneGraph
{
	protected:
		struct RenderGroup
		{

			bool render;	// should this group be rendered?
			bool selectable;	// are the elements in this group selectable?

			std::list<SceneGraphComponent *> primitive_components;	// list of primitive components included in this group

			SceneGraphComponent scenegraph;

			RenderGroup();

			/*
			   Generate a new scenegraph tree from the current list of primitive components
			*/
			void generateSceneGraph();
		};
	public:
		enum Groups 	// common groups for all scenegraphs
		{
			RG_NODES,	// the element nodes
			RG_SURFACES,	// the opaque surfaces used in ModelViewport an DisplacementsViewport
			RG_WIREFRAME,	// wireframe of the opaque surfaces.  This group and RG_SURFACES are mutually explusive
			RG_GHOST_SURFACES	// surfaces rendered in the displacement viewport to show the model's original configuration
		};

	public:
		/* 
		This is the master list of all scene graph objects in this scene graph.
		It is used to store every object of type SGCSurface (etc...) managed by this scenegraph.
		*/
		std::list<SceneGraphComponent *> primitive_components;

		std::map<int, RenderGroup>	rendering_groups;

	public:
		SceneGraph();
		~SceneGraph();


		/*
		Clears all the data structures managed by this class
		*/
		void clear();


		void paint(ViewportData &viewport_data, fem::Model &model, ViewportColors &colors);

		/*
		Generic routine to add a primitive component to this scenegraph
		The template was provided for syntax convenience only; this class only accepts specific types derived from SceneGraphComponent
		@param group	destination RenderGroup
		@param *newcomponent	new scenegraph component
		*/
		void addPrimitiveComponent(int group, SceneGraphComponent *new_component);

		/*
		Generate a new scenegraph tree from the current list of primitive components
		*/
		void generateSceneGraph();
};

#endif
