#ifndef FEMP_SURFACE_LOAD_HPP
#define FEMP_SURFACE_LOAD_HPP

#include <vector>

#include <libfemp/Element.h++>
#include <libfemp/Point.h++>

namespace fem
{


/**
 * Represents a pressure applied on a surface
 **/
class SurfaceLoad
	: public Element
{
public:
	std::vector<fem::Point>	surface_forces;	// forces acting in each node, used to interpolate the surface load

public:
	SurfaceLoad();
	SurfaceLoad(const SurfaceLoad &);
	~SurfaceLoad();

	/**
	Clears all attributes
	**/
	void clear();
};

}	// namespace fem

#endif
