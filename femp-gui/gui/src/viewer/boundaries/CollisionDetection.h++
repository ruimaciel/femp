#ifndef COLLISION_DETECTION_HPP
#define COLLISION_DETECTION_HPP

#include "SphericalBoundary.h++"

#include <libfemp/Point3D.h++>

/*
Detects a collision between a ray, described by two points, and a sphere
*/
bool collided(const SphericalBoundary& sphere, const fem::Point3D& near, const fem::Point3D& far);

#endif
