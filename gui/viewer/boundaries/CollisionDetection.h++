#ifndef COLLISION_DETECTION_HPP
#define COLLISION_DETECTION_HPP

#include "SphericalBoundary.h++"

#include <libfemp/Point.h++>


/*
Detects a collision between a ray, described by two points, and a sphere
*/
bool collided(const SphericalBoundary &sphere, const fem::Point &near, const fem::Point &far);


#endif
