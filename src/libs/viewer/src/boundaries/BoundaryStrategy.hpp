#ifndef FEMP_VIEWER_BOUNDARYSTRATEGY_HPP
#define FEMP_VIEWER_BOUNDARYSTRATEGY_HPP

#include <libfemp/Point3D.hpp>

/**
 * Provides the interface for a generic boundary volume through a strategy
 *pattern
 **/

class BoundaryStrategy {
	public:
	BoundaryStrategy();
	~BoundaryStrategy();

	/**
	 * Checks if a given fem::Point is inside this boundary
	 * @return	true if it is, false if it isn't
	 **/
	virtual bool inside(const fem::Point3D&) = 0;

	virtual void setPoint(const fem::Point3D&) = 0;

	/**
	 * Resizes the spherical boundary, if needed, to include a new fem::Point
	 **/
	virtual void addPoint(const fem::Point3D&) = 0;
};

#endif
