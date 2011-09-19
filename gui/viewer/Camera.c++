#include "Camera.h++"


Camera::Camera()
{
}


Camera::~Camera()
{
}


void 
Camera::setCenter(double x, double y, double z)
{
	center.set(x,y,z);
}


void 
Camera::setPosition(double x, double y, double z)
{
	pos.set(x,y,z);
}


void 
Camera::reset()
{
	pos = center;
	rotation.set(0,0,0);
}


void 
Camera::reposition()
{
	glTranslated(center.x(),center.y(), center.z());
	glRotated(rotation.data[0], 1.0, 0.0, 0.0);
	glRotated(rotation.data[1], 0.0, 1.0, 0.0);
	glRotated(rotation.data[2], 0.0, 0.0, 1.0);
	glTranslated(pos.x(),pos.y(),pos.z());
}
