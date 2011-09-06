#ifndef CAMERA_HH
#define CAMERA_HH

#include <fem/point.h++>

#include <sigc++/sigc++.h> 	// to side step a compiler error caused by a conflict with Qt and libsigc++
#include <GL/gl.h>


class Camera 
{
public:
	fem::point center;
	fem::point pos;
	fem::point rotation;

public:
	Camera();
	~Camera();

	void setCenter(double x, double y, double z);
	void setPosition(double x, double y, double z);
	void reset();

	/**
	This routine is to be used at the start of the main opengl rendering routine
	it calls opengl routines to position the camera relative to the scene
	**/
	void reposition();
};

#endif
