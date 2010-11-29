#ifndef SCENE_GRAPH_COMPONENT_SURFACE_HPP
#define SCENE_GRAPH_COMPONENT_SURFACE_HPP


#include "SceneGraphComponent.h++"

#include "ViewportData.h++"
#include "ViewportColors.h++"

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
		void paintGL(ViewportData &data, fem::Model *model, ViewportColors &colors);

	protected:
		void renderLine3(const fem::point &p1, const fem::point &p2, const fem::point &p3, int partitions = 1);
		void renderQuad4(const fem::point &p1, const fem::point &p2,const fem::point &p3,const fem::point &p4, int partitions = 1);
		void renderQuad8(const fem::point &p1, const fem::point &p2, const fem::point &p3, const fem::point &p4,const fem::point &p5, const fem::point &p6, const fem::point &p7, const fem::point &p8, int partitions = 1);
		void renderQuad9(const fem::point &p1, const fem::point &p2, const fem::point &p3, const fem::point &p4,const fem::point &p5, const fem::point &p6, const fem::point &p7, const fem::point &p8, const fem::point &p9, int partitions = 1);
		void renderTriangle3(const fem::point &p1, const fem::point &p2,const fem::point &p3, int partitions = 1);
		void renderTriangle6(const fem::point &p1, const fem::point &p2,const fem::point &p3,const fem::point &p4, const fem::point &p5, const fem::point &p6, int partitions = 1);

		/*
		Visitor pattern method
		*/
		void accept(OperationsVisitor &v);
};


#endif
