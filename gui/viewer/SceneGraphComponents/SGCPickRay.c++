#include "SGCPickRay.h++"

#include <GL/gl.h>
#include <GL/glu.h>

#include <assert.h>


namespace SGC
{


PickRay::PickRay(fem::point const &origin,fem::point const &destination, float const &radius)
	: SceneGraphComponent()
{
	m_origin = origin;
	m_destination = destination;
	this->radius = radius;
}


PickRay::~PickRay()
{
}


void PickRay::paintGL(ViewportData &data, ViewportColors &colors)
{
	glPushMatrix();

	glBegin(GL_LINES);
	glVertex3dv(m_origin.data);
	glVertex3dv(m_destination.data);
	glEnd();

	glPopMatrix();
}


void PickRay::accept(Operation::OperationsVisitor &visitor)
{
	visitor.visit(*this);
}


}	// namespace SGC


