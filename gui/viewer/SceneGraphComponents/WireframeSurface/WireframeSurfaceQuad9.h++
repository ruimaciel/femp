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
		void paintGL(ViewportData &data, fem::Model *model, ViewportColors &colors, std::map<size_t, fem::Node> *node_list, fem::Surface *surface);
};


void WireframeSurfaceQuad9::paintGL(ViewportData &data, fem::Model *model, ViewportColors &colors, std::map<size_t, fem::Node> *node_list, fem::Surface *surface)
{
	int partitions = 6;	//TODO implement a better code

	// temp code to help with the copy/paste
	fem::point p1 = (*node_list)[surface->nodes[0]];
	fem::point p2 = (*node_list)[surface->nodes[1]];
	fem::point p3 = (*node_list)[surface->nodes[2]];
	fem::point p4 = (*node_list)[surface->nodes[3]];
	fem::point p5 = (*node_list)[surface->nodes[4]];
	fem::point p6 = (*node_list)[surface->nodes[5]];
	fem::point p7 = (*node_list)[surface->nodes[6]];
	fem::point p8 = (*node_list)[surface->nodes[7]];
	fem::point p9 = (*node_list)[surface->nodes[8]];
	
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
