#ifndef CAMERA_HH
#define CAMERA_HH

#include <fem/point.h++>


class Camera 
{
	public:
		fem::point pos;
		fem::point rotation;

	public:
		Camera();
		~Camera();
};

#endif
