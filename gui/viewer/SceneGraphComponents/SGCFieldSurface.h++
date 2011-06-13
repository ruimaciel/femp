#ifndef SCENE_GRAPH_COMPONENT_FIELD_SURFACE_HPP
#define SCENE_GRAPH_COMPONENT_FIELD_SURFACE_HPP


#include "SceneGraphComponent.h++"

#include "../ViewportStates/FieldComponent.h++"
#include "../ViewportData.h++"
#include "../ViewportColors.h++"

#include "../../fem/Surface.h++"


template<class SurfacePolicy>
class SGCFieldSurface
	: public SceneGraphComponent, public SurfacePolicy
{
	protected:
		fem::Surface *surface;	// pointer to the referenced surface object which is a part of fem::Model::surface_list
		FieldComponent **component;	// pointer to a pointer to a FieldComponent object.  With this, if the FieldComponent pointer changes then this will incorporate the change

	public:
		/*
		@param	reference_surface	the reference to this surface's fem::Surface object
		@param	reference_nodes	a map which links this surface's nodes to their displaced value
		*/
		SGCFieldSurface(fem::Surface &reference_surface, FieldComponent * &component);
		~SGCFieldSurface();

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
SGCFieldSurface<SurfacePolicy>::SGCFieldSurface(fem::Surface &reference_surface, FieldComponent * &component)
	: SceneGraphComponent(), SurfacePolicy()
{
	assert(component != NULL);

	this->component = &component;
	this->setReferenceSurface(reference_surface);
}


template<class SurfacePolicy>
SGCFieldSurface<SurfacePolicy>::~SGCFieldSurface()
{
}


template<class SurfacePolicy>
void SGCFieldSurface<SurfacePolicy>::setReferenceSurface(fem::Surface &referenced_surface)
{
	this->surface = &referenced_surface;

	//TODO adjust boundary to this surface
}


template<class SurfacePolicy>
void SGCFieldSurface<SurfacePolicy>::paintGL(ViewportData &data, fem::Project &project, fem::AnalysisResult<double> *result, float &scale,  ViewportColors &colors)
{
	assert(this->component != NULL);

	glColor3fv(colors.surface);
	SurfacePolicy::paintGL(data, project, result, **this->component, scale, colors, surface);
}


template<class SurfacePolicy>
void SGCFieldSurface<SurfacePolicy>::accept(OperationsVisitor &v)
{
	v.visit(*this);
}

#endif
