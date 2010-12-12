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
		std::map<size_t, fem::Node> *nodes;


	public:
		SGCDisplacementSurface(fem::Surface &, std::map<size_t, fem::Node> &);
		~SGCDisplacementSurface();

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
SGCDisplacementSurface<SurfacePolicy>::SGCDisplacementSurface(fem::Surface &reference_surface, std::map<size_t, fem::Node> &reference_nodes)
	: SceneGraphComponent(), SurfacePolicy()
{
	this->setReferenceSurface(reference_surface);
	this->setReferenceNodes(reference_nodes);
}


template<class SurfacePolicy>
SGCDisplacementSurface<SurfacePolicy>::~SGCDisplacementSurface()
{
}


template<class SurfacePolicy>
void SGCDisplacementSurface<SurfacePolicy>::setReferenceNodes( std::map<size_t, fem::Node> &reference_nodes)
{
	this->nodes = &reference_nodes;
}


template<class SurfacePolicy>
void SGCDisplacementSurface<SurfacePolicy>::setReferenceSurface(fem::Surface &referenced_surface)
{
	this->surface = &referenced_surface;

	/*
	mylog.setPrefix("SGCDisplacementSurface::setReferenceSurface()");
	mylog.message("yet to be implemented");
	*/

	//TODO adjust boundary to this surface
}


template<class SurfacePolicy>
void SGCDisplacementSurface<SurfacePolicy>::paintGL(ViewportData &data, fem::Model *model, ViewportColors &colors)
{
	glColor3fv(colors.surface);
	SurfacePolicy::paintGL(data, model, nodes, surface);
}


template<class SurfacePolicy>
void SGCDisplacementSurface<SurfacePolicy>::accept(OperationsVisitor &v)
{
	v.visit(*this);
}

#endif
