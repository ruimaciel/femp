#ifndef SCENE_GRAPH_COMPONENT_FIELD_TRIANGLE_3_HPP
#define SCENE_GRAPH_COMPONENT_FIELD_TRIANGLE_3_HPP


#include <map>
#include "FieldSurface.h++"
#include "../../ViewportStates/FieldComponent.h++"
#include "../../ViewportData.h++"
#include "../../ViewportColors.h++"
#include "../../../fem/Project.h++"
#include "../../../fem/Node.h++"
#include "../../../fem/Surface.h++"


/*
Policy class to implemente the SGCDisplacementSurface through a template policy pattern
*/
class FieldSurfaceTriangle3
	: public FieldSurface
{
	public:
		FieldSurfaceTriangle3();

		void paintGL(ViewportData &data, fem::Project &project, fem::AnalysisResult<double> *result, FieldComponent &field, float &scale, ViewportColors &colors, fem::Surface *surface);
};


FieldSurfaceTriangle3::FieldSurfaceTriangle3()
{
	this->color_value.resize(3);
}


void FieldSurfaceTriangle3::paintGL(ViewportData &, fem::Project &project, fem::AnalysisResult<double> *result, FieldComponent &field, float &scale, ViewportColors &colors, fem::Surface *surface)
{
	glEnable(GL_BLEND);
	glDisable(GL_LIGHTING);
	using namespace fem;

	//int partitions = 4;	//TODO implement a better code

	// temp code to help with the copy/paste
	fem::point p1 = project.model.node_list[surface->nodes[0]] + scale* result->displacements[surface->nodes[0]];
	fem::point p2 = project.model.node_list[surface->nodes[1]] + scale* result->displacements[surface->nodes[1]];
	fem::point p3 = project.model.node_list[surface->nodes[2]] + scale* result->displacements[surface->nodes[2]];

	// sets the field colors for a particular field defined through a state pattern
	field.Triangle3(color_value, project, *result, *surface, colors);
	
	fem::point temp;
	temp = getNormalVector(p1,p2,p3);
	
	glBegin(GL_TRIANGLES);
	glNormal3dv(temp.data);
	glVertex3dv(p1.data);
	glVertex3dv(p2.data);
	glVertex3dv(p3.data);
	glEnd();
	glDisable(GL_BLEND);
	glEnable(GL_LIGHTING);
}

#endif
