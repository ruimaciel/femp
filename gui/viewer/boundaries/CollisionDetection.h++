#ifndef COLLISION_DETECTION_HPP
#define COLLISION_DETECTION_HPP

#include "SphericalBoundary.h++"
#include "../../point.h++"


/*
Detects a collision between a ray, described by two points, and a sphere
*/
bool collided(const SphericalBoundary &sphere, const fem::point &near, const fem::point &far);


#endif
