#ifndef SCENE_GRAPH_COMPONENT_MODEL_ORIGINAL_SURFACE_HPP
#define SCENE_GRAPH_COMPONENT_MODEL_ORIGINAL_SURFACE_HPP


#include "SceneGraphComponent.h++"

#include "../ViewportData.h++"
#include "../ViewportColors.h++"

#include "../../fem/Surface.h++"


template<class SurfacePolicy>
class SGCModelSurface
	: public SceneGraphComponent, public SurfacePolicy
{
	protected:
		fem::Surface *surface;	// pointer to the referenced surface object which is a part of fem::Model::surface_list
		std::map<size_t, fem::Node> *nodes;


	public:
		SGCModelSurface(fem::Surface &, std::map<size_t, fem::Node> &);
		~SGCModelSurface();

		/*
		Specifies the reference surface for this scenegraph component
		It also adjusts the boundary volume
		*/
		void setReferenceNodes( std::map<size_t, fem::Node> 	&);

		void setReferenceSurface(fem::Surface &);
		
		/*
		Renders this surface according to the surface type and the detail factor
		*/
		void paintGL(ViewportData &data, fem::Model *model, ViewportColors &colors);

	protected:
		/*
		Visitor pattern method
		*/
		void accept(OperationsVisitor &v);
};


template<class SurfacePolicy>
SGCModelSurface<SurfacePolicy>::SGCModelSurface(fem::Surface &reference_surface, std::map<size_t, fem::Node> &reference_nodes)
	: SceneGraphComponent(), SurfacePolicy()
{
	this->setReferenceSurface(reference_surface);
	this->setReferenceNodes(reference_nodes);
}


template<class SurfacePolicy>
SGCModelSurface<SurfacePolicy>::~SGCModelSurface()
{
}


template<class SurfacePolicy>
void SGCModelSurface<SurfacePolicy>::setReferenceNodes( std::map<size_t, fem::Node> &reference_nodes)
{
	this->nodes = &reference_nodes;
}


template<class SurfacePolicy>
void SGCModelSurface<SurfacePolicy>::setReferenceSurface(fem::Surface &referenced_surface)
{
	this->surface = &referenced_surface;

	/*
	mylog.setPrefix("SGCModelSurface::setReferenceSurface()");
	mylog.message("yet to be implemented");
	*/

	//TODO adjust boundary to this surface
}


template<class SurfacePolicy>
void SGCModelSurface<SurfacePolicy>::paintGL(ViewportData &data, fem::Model *model, ViewportColors &colors)
{
	glEnable(GL_BLEND);
	glColor4fv(colors.original_surface);
	SurfacePolicy::paintGL(data, model, nodes, surface);
	glDisable(GL_BLEND);
}


template<class SurfacePolicy>
void SGCModelSurface<SurfacePolicy>::accept(OperationsVisitor &v)
{
	v.visit(*this);
}

#endif
