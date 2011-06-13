#ifndef SCENE_GRAPH_COMPONENT_DISPLACEMENT_SURFACE_HPP
#define SCENE_GRAPH_COMPONENT_DISPLACEMENT_SURFACE_HPP


#include "SceneGraphComponent.h++"

#include "../ViewportData.h++"
#include "../ViewportColors.h++"

#include "../../fem/Surface.h++"


template<class SurfacePolicy>
class SGCDisplacementSurface
	: public SceneGraphComponent, public SurfacePolicy
{
	protected:
		fem::Surface *surface;	// pointer to the referenced surface object which is a part of fem::Model::surface_list

	public:
		/*
		@param	reference_surface	the reference to this surface's fem::Surface object
		@param	reference_nodes	a map which links this surface's nodes to their displaced value
		*/
		SGCDisplacementSurface(fem::Surface &reference_surface);
		~SGCDisplacementSurface();

		void setReferenceSurface(fem::Surface &);
		
		/*
		Renders this surface according to the surface type and the detail factor
		*/
		void paintGL(ViewportData &data, fem::Project &project, fem::AnalysisResult<double> *result, float &scale, ViewportColors &colors);

	protected:
		/*
		Visitor pattern method
		*/
		void accept(OperationsVisitor &v);
};


template<class SurfacePolicy>
SGCDisplacementSurface<SurfacePolicy>::SGCDisplacementSurface(fem::Surface &reference_surface)
	: SceneGraphComponent(), SurfacePolicy()
{
	this->setReferenceSurface(reference_surface);
}


template<class SurfacePolicy>
SGCDisplacementSurface<SurfacePolicy>::~SGCDisplacementSurface()
{
}


template<class SurfacePolicy>
void SGCDisplacementSurface<SurfacePolicy>::setReferenceSurface(fem::Surface &referenced_surface)
{
	this->surface = &referenced_surface;

	//TODO adjust boundary to this surface
}


template<class SurfacePolicy>
void SGCDisplacementSurface<SurfacePolicy>::paintGL(ViewportData &data, fem::Project &project, fem::AnalysisResult<double> *result, float &scale,  ViewportColors &colors)
{
	glColor3fv(colors.surface);
	SurfacePolicy::paintGL(data, project, result, scale, colors, surface);
}


template<class SurfacePolicy>
void SGCDisplacementSurface<SurfacePolicy>::accept(OperationsVisitor &v)
{
	v.visit(*this);
}

#endif
