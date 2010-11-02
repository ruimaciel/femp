#include "SGCSurface.h++"

#include <GL/gl.h>

#include "Logs.h++"	// declare the global message loggers


SGCSurface::SGCSurface()
{
}


SGCSurface::~SGCSurface()
{
}


void SGCSurface::setReferenceSurface(fem::Surface &referenced_surface)
{
	this->surface = &referenced_surface;

	//TODO adjust boundary to this surface
}


void SGCSurface::paintGL(fem::Model *model, ViewportColors *colors)
{
	assert(model != NULL);
	using namespace fem;

	mylog.setPrefix("SGCSurface::paintGL()");
	mylog.message("yet to be implemented");

	//TODO must implement this
	switch(surface->type)
	{
		case Element::FE_TRIANGLE3:
			renderTriangle3(model->node_list[surface->nodes[0]], model->node_list[surface->nodes[1]], model->node_list[surface->nodes[2]]);
			break;
		
		case Element::FE_TRIANGLE6:
			break;
		
		case Element::FE_QUADRANGLE4:
			break;
		
		default:
			mylog.message("unknown surface type");
			break;
	}
}


inline void SGCSurface::renderTriangle3(const fem::point &p1, const fem::point &p2, const fem::point &p3)
{
	//TODO implement the zoom refining feature
	int partitions = 1;
	fem::point temp;
	temp = getNormalVector(p1,p2,p3);
	glBegin(GL_TRIANGLES);
	glNormal3dv(temp.data);
	glVertex3dv(p1.data);
	glVertex3dv(p2.data);
	glVertex3dv(p3.data);
	glEnd();
}
