#ifndef BOUNDARY_STRATEGY_HPP
#define BOUNDARY_STRATEGY_HPP


#include "../../point.h++"

/*
Provides the interface for a generic boundary volume through a strategy pattern
*/

class BoundaryStrategy
{
	public:
		BoundaryStrategy();
		~BoundaryStrategy();

		/*
		Checks if a given fem::point is inside this boundary
		@return	true if it is, false if it isn't
		*/
		virtual bool inside(const fem::point &) = 0;


		virtual void setPoint(const fem::point &) = 0;
		/*
		Resizes the spherical boundary, if needed, to include a new fem::point
		*/
		virtual void addPoint(const fem::point &) = 0;
};

#endif
