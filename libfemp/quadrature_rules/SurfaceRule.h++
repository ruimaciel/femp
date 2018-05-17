#ifndef SURFACERULE_H
#define SURFACERULE_H

#include <vector>
#include "QuadraturePoint.h++"


namespace fem
{
namespace quadrature
{


/**
 * Interface used by all quadrature rules over the square
 **/
class SurfaceRule
{
public:
	typedef QuadraturePoint<2> Point;	// helper alias

public:
	virtual ~SurfaceRule() {}

	/**
	 * functor that returns the quadrature rule
	 **/
	virtual std::vector<Point> operator() () const = 0;
};


}	// namespace quadrature
}	// namespace fem


#endif // SURFACERULE_H
