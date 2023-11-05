#ifndef FEMP_VIEWER_CAMERA_HPP
#define FEMP_VIEWER_CAMERA_HPP

// libfemp includes
#include <libfemp/Point3D.hpp>

class Camera {
	public:
	void setCenter(double x, double y, double z);

	void setPosition(double x, double y, double z);

	void setRotation(fem::Point3D rotation);

	void reset();

	/**
	 * This routine is to be used at the start of the main opengl rendering
	 * routine it calls opengl routines to position the camera relative to the
	 * scene
	 */
	void reposition();

	fem::Point3D getCenter() const;

	fem::Point3D getPosition() const;

	fem::Point3D getRotation() const;

	private:
	fem::Point3D m_center;
	fem::Point3D m_pos;
	fem::Point3D m_rotation;
};

#endif
