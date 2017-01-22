#ifndef CAMERA_HH
#define CAMERA_HH

#include <sigc++/sigc++.h> 	// to side step a compiler error caused by a conflict with Qt and libsigc++
#include <GL/gl.h>

#include <libfemp/Point.h++>


class Camera 
{
public:
	fem::Point center;
	fem::Point pos;
	fem::Point rotation;

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
