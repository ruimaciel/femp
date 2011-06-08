#ifndef SCENE_GRAPH_COMPONENT_WIREFRAME_QUAD_4_HPP
#define SCENE_GRAPH_COMPONENT_WIREFRAME_QUAD_4_HPP


#include <map>
#include "../../ViewportData.h++"
#include "../../../fem/Model.h++"
#include "../../../fem/Node.h++"
#include "../../../fem/Surface.h++"


/*
Policy class to implemente the SGCDisplacementSurface through a template policy pattern
*/
class WireframeSurfaceQuad4
{
	public:
		void paintGL(ViewportData &data, fem::Model *model, ViewportColors &colors, std::map<size_t, fem::Node> *node_list, fem::Surface *surface);
};



void WireframeSurfaceQuad4::paintGL(ViewportData &, fem::Model *, ViewportColors &colors, std::map<size_t, fem::Node> *node_list, fem::Surface *surface)
{
	//int partitions = 3;	//TODO implement a better code

	// temp code to help with the copy/paste
	fem::point p1 = (*node_list)[surface->nodes[0]];
	fem::point p2 = (*node_list)[surface->nodes[1]];
	fem::point p3 = (*node_list)[surface->nodes[2]];
	fem::point p4 = (*node_list)[surface->nodes[3]];
	
/*
	^ y
	|
	4 ------ 3
	|        |
	|        |
	|        |
	1 ------ 2 --> x
*/

	glColor3fv(colors.wireframe);
	glBegin(GL_LINE_STRIP);
	glVertex3dv(p1.data);
	glVertex3dv(p2.data);
	glVertex3dv(p3.data);
	glVertex3dv(p4.data);
	glVertex3dv(p1.data);
	glEnd();
}

#endif
