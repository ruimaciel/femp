#ifndef SPHERE_BOUNDARY_STRATEGY_HPP
#define SPHERE_BOUNDARY_STRATEGY_HPP

#include "BoundaryStrategy.h++"

#include <libfemp/Point3D.h++>

/*
A concrete class that implements a sphere boundary throught the Boundary strategy pattern
*/
class SphericalBoundary
    : public BoundaryStrategy {
public:
    fem::Point3D center; // sphere center
    float radius2; // the square of the sphere's radius

public:
    SphericalBoundary();
    ~SphericalBoundary();

    /*
		Checks if a given point is inside this boundary
		@return	true if it is, false if it isn't
		*/
    bool inside(const fem::Point3D&);

    /*
		Sets this sphere's starting point
		*/
    void setPoint(const fem::Point3D&);

    /*
		Resizes the spherical boundary, if needed, to include a new point
		*/
    void addPoint(const fem::Point3D&);
};

#endif
