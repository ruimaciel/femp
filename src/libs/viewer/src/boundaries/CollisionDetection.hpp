#ifndef FEMP_VIEWER_COLLISIONDETECTION_HPP
#define FEMP_VIEWER_COLLISIONDETECTION_HPP

#include <libfemp/Point3D.hpp>

#include "SphericalBoundary.hpp"

/**
 * Detects a collision between a ray, described by two points, and a sphere
 **/
bool collided(const SphericalBoundary& sphere, const fem::Point3D& near, const fem::Point3D& far);

#endif
