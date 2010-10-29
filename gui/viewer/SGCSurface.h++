#ifndef SCENE_GRAPH_COMPONENT_SURFACE_HPP
#define SCENE_GRAPH_COMPONENT_SURFACE_HPP


#include "SceneGraphComponent.h++"

#include "../fem/Surface.h++"


class SGCSurface
	: public SceneGraphComponent
{
	protected:
		fem::Surface *surface;	// pointer to the referenced surface object which is a part of fem::Model::surface_list

	public:
		SGCSurface();
		~SGCSurface();


		/*
		Specifies the reference surface for this scenegraph component
		It also adjusts the boundary volume
		*/
		void setReferenceSurface(fem::Surface &);
		
		/*
		Renders this surface according to the surface type and the detail factor
		*/
		void paintGL();
};


#endif
