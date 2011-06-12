#ifndef SCENE_GRAPH_COMPONENT_FIELD_SURFACE_HPP
#define SCENE_GRAPH_COMPONENT_FIELD_SURFACE_HPP

#include "SceneGraphComponent.h++"

#include "../ViewportData.h++"
#include "../ViewportColors.h++"

#include "../../fem/Project.h++"
#include "../../fem/AnalysisResult.h++"
#include "../../fem/Node.h++"
#include "../../fem/Surface.h++"


/**
SceneGraph component designed to represent fields as a color gradient in a surface
**/
template<class SurfacePolicy>
class SGCFieldSurface
	: public SceneGraphComponent, public SurfacePolicy
{
	protected:
		fem::Surface *surface;	// pointer to the referenced surface object which is a part of fem::Model::surface_list
		std::map<size_t, fem::Node> *nodes;
		fem::RecoveredValues<double> *values;


	public:
		/*
		@param	reference_surface	the reference to this surface's fem::Surface object
		@param	reference_nodes	a map which links this surface's nodes to their displaced value
		*/
		SGCFieldSurface(fem::Surface &reference_surface, std::map<size_t, fem::Node> &reference_nodes);
		~SGCFieldSurface();

		/*
		Specifies the reference surface for this scenegraph component
		It also adjusts the boundary volume
		*/
		void setReferenceNodes( std::map<size_t, fem::Node> 	&);

		void setReferenceSurface(fem::Surface &);
		
		/*
		Renders this surface according to the surface type and the detail factor
		*/
		void paintGL(ViewportData &data, fem::Project &project, ViewportColors &colors);

	protected:
		/*
		Visitor pattern method
		*/
		void accept(OperationsVisitor &v);
};


template<class SurfacePolicy>
SGCFieldSurface<SurfacePolicy>::SGCFieldSurface(fem::Surface &reference_surface, std::map<size_t, fem::Node> &reference_nodes)
	: SceneGraphComponent(), SurfacePolicy()
{
	this->setReferenceSurface(reference_surface);
	this->setReferenceNodes(reference_nodes);
}


template<class SurfacePolicy>
SGCFieldSurface<SurfacePolicy>::~SGCFieldSurface()
{
}


template<class SurfacePolicy>
void SGCFieldSurface<SurfacePolicy>::setReferenceNodes( std::map<size_t, fem::Node> &reference_nodes)
{
	this->nodes = &reference_nodes;
}


template<class SurfacePolicy>
void SGCFieldSurface<SurfacePolicy>::setReferenceSurface(fem::Surface &referenced_surface)
{
	this->surface = &referenced_surface;

	/*
	mylog.setPrefix("SGCFieldSurface::setReferenceSurface()");
	mylog.message("yet to be implemented");
	*/

	//TODO adjust boundary to this surface
}


template<class SurfacePolicy>
void SGCFieldSurface<SurfacePolicy>::paintGL(ViewportData &data, fem::Project &project, ViewportColors &colors)
{
	SurfacePolicy::paintGL(data, project, colors, nodes, surface);
}


template<class SurfacePolicy>
void SGCFieldSurface<SurfacePolicy>::accept(OperationsVisitor &v)
{
	v.visit(*this);
}

#endif
