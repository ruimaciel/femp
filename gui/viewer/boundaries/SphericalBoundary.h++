#ifndef SPHERE_BOUNDARY_STRATEGY_HPP
#define SPHERE_BOUNDARY_STRATEGY_HPP

#include "BoundaryStrategy.h++"

#include <libfemp/point.h++>

/*
A concrete class that implements a sphere boundary throught the Boundary strategy pattern
*/
class SphericalBoundary
	: public BoundaryStrategy
{
	public:
		fem::point center;	// sphere center
		float radius2;	// the square of the sphere's radius
		
	public:
		SphericalBoundary();
		~SphericalBoundary();

		/*
		Checks if a given point is inside this boundary
		@return	true if it is, false if it isn't
		*/
		bool inside(const fem::point &);

		/*
		Sets this sphere's starting point
		*/
		void setPoint(const fem::point &);

		/*
		Resizes the spherical boundary, if needed, to include a new point
		*/
		void addPoint(const fem::point &);
};

#endif
