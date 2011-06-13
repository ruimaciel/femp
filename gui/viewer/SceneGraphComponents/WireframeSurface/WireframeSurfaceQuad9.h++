#ifndef SCENE_GRAPH_COMPONENT_WIREFRAME_QUAD_9_HPP
#define SCENE_GRAPH_COMPONENT_WIREFRAME_QUAD_9_HPP


#include <map>
#include "../../ViewportData.h++"
#include "../../../fem/Model.h++"
#include "../../../fem/Node.h++"
#include "../../../fem/Surface.h++"

/*
Policy class to implemente the SGCDisplacementSurface through a template policy pattern
*/
class WireframeSurfaceQuad9
{
	public:
		void paintGL(ViewportData &data, fem::Project &project,fem::AnalysisResult<double> *result, float &scale,  ViewportColors &colors, fem::Surface *surface);
};


void WireframeSurfaceQuad9::paintGL(ViewportData &, fem::Project &project, fem::AnalysisResult<double> *result, float &scale, ViewportColors &colors, fem::Surface *surface)
{
	int partitions = 6;	//TODO implement a better code

	// temp code to help with the copy/paste
	fem::point p1 = project.model.node_list[surface->nodes[0]]+ result->displacements[surface->nodes[0]];
	fem::point p2 = project.model.node_list[surface->nodes[1]]+ result->displacements[surface->nodes[1]];
	fem::point p3 = project.model.node_list[surface->nodes[2]]+ result->displacements[surface->nodes[2]];
	fem::point p4 = project.model.node_list[surface->nodes[3]]+ result->displacements[surface->nodes[3]];
	fem::point p5 = project.model.node_list[surface->nodes[4]]+ result->displacements[surface->nodes[4]];
	fem::point p6 = project.model.node_list[surface->nodes[5]]+ result->displacements[surface->nodes[5]];
	fem::point p7 = project.model.node_list[surface->nodes[6]]+ result->displacements[surface->nodes[6]];
	fem::point p8 = project.model.node_list[surface->nodes[7]]+ result->displacements[surface->nodes[7]];
	fem::point p9 = project.model.node_list[surface->nodes[8]]+ result->displacements[surface->nodes[8]];
	
/*
	^ y
	|
	4 -- 7 -- 3
	|         |
	8    9    6
	|         |
	1 -- 5 -- 2 --> x
*/
	glColor3fv(colors.wireframe);
	glBegin(GL_LINE_STRIP); 
	for(int i = 0; i <= partitions; i++) 
	{ 
		float x = i/(float)partitions; 
		glVertex3dv( (2.0*p2*(x-0.5)*x - 4.0*p5*(x-1)*x + 2.0*p1*(x-1)*(x-0.5)).data); 
	} 
	glEnd();
	glBegin(GL_LINE_STRIP); 
	for(int i = 0; i <= partitions; i++) 
	{ 
		float x = i/(float)partitions; 
		glVertex3dv( (2.0*p3*(x-0.5)*x - 4.0*p6*(x-1)*x + 2.0*p2*(x-1)*(x-0.5)).data); 
	} 
	glEnd();
	glBegin(GL_LINE_STRIP); 
	for(int i = 0; i <= partitions; i++) 
	{ 
		float x = i/(float)partitions; 
		glVertex3dv( (2.0*p4*(x-0.5)*x - 4.0*p7*(x-1)*x + 2.0*p3*(x-1)*(x-0.5)).data); 
	} 
	glEnd();
	glBegin(GL_LINE_STRIP); 
	for(int i = 0; i <= partitions; i++) 
	{ 
		float x = i/(float)partitions; 
		glVertex3dv( (2.0*p1*(x-0.5)*x - 4.0*p8*(x-1)*x + 2.0*p4*(x-1)*(x-0.5)).data); 
	} 
	glEnd();
}

#endif
