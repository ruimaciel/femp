#include <GL/gl.h>

#include <viewer/Camera.h++>

void Camera::setCenter(double x, double y, double z) {
	m_center.set(x, y, z);
}

void Camera::setPosition(double x, double y, double z) {
	m_pos.set(x, y, z);
}

void Camera::setRotation(fem::Point3D rotation) {
	this->m_rotation = rotation;
}

void Camera::reset() {
	m_pos = m_center = fem::Point3D(0, 0, 0);
	m_rotation.set(0, 0, 0);
}

void Camera::reposition() {
	glTranslated(m_center.x(), m_center.y(), m_center.z());
	glRotated(m_rotation.data[0], 1.0, 0.0, 0.0);
	glRotated(m_rotation.data[1], 0.0, 1.0, 0.0);
	glRotated(m_rotation.data[2], 0.0, 0.0, 1.0);
	glTranslated(m_pos.x(), m_pos.y(), m_pos.z());
}

fem::Point3D Camera::getCenter() const {
	return m_center;
}

fem::Point3D Camera::getPosition() const {
	return m_pos;
}

fem::Point3D Camera::getRotation() const {
	return this->m_rotation;
}
