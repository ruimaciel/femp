#ifndef SCENE_GRAPH_COMPONENT_WIREFRAME_TRIANGLE_3_HPP
#define SCENE_GRAPH_COMPONENT_WIREFRAME_TRIANGLE_3_HPP


#include <map>
#include "../../ViewportData.h++"
#include "../../../fem/Model.h++"
#include "../../../fem/Node.h++"
#include "../../../fem/Surface.h++"

/*
Policy class to implemente the SGCDisplacementSurface through a template policy pattern
*/
class WireframeSurfaceTriangle3
{
	public:
		void paintGL(ViewportData &data, fem::Model *model, ViewportColors &colors, std::map<size_t, fem::Node> *node_list, fem::Surface *surface);
};


void WireframeSurfaceTriangle3::paintGL(ViewportData &data, fem::Model *model, ViewportColors &colors, std::map<size_t, fem::Node> *node_list, fem::Surface *surface)
{
	using namespace fem;

	int partitions = 4;	//TODO implement a better code

	fem::point p1 = (*node_list)[surface->nodes[0]];
	fem::point p2 = (*node_list)[surface->nodes[1]];
	fem::point p3 = (*node_list)[surface->nodes[2]];

	glColor3fv(colors.wireframe);
	glBegin(GL_LINE_STRIP);
	glVertex3dv(p1.data);
	glVertex3dv(p2.data);
	glVertex3dv(p3.data);
	glVertex3dv(p1.data);
	glEnd();
}

#endif