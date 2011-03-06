#include "SurfaceTriangle3.h++"

#include "../fem/point.h++"


void SurfaceTriangle3::paintGL(ViewportData &data, fem::Model *model, ViewportColors &colors, std::map<size_t, fem::Node> *node_list, fem::Surface *surface)
{
	glEnable(GL_BLEND);
	using namespace fem;

	int partitions = 4;	//TODO implement a better code

	// temp code to help with the copy/paste
	fem::point p1 = (*node_list)[surface->nodes[0]];
	fem::point p2 = (*node_list)[surface->nodes[1]];
	fem::point p3 = (*node_list)[surface->nodes[2]];

	fem::point temp;
	temp = getNormalVector(p1,p2,p3);
	
	glBegin(GL_TRIANGLES);
	glNormal3dv(temp.data);
	glVertex3dv(p1.data);
	glVertex3dv(p2.data);
	glVertex3dv(p3.data);
	glEnd();
	glDisable(GL_BLEND);
}

