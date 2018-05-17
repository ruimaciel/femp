#ifndef VOLUMERULE_H
#define VOLUMERULE_H

#include <vector>
#include "QuadraturePoint.h++"

namespace fem
{
namespace quadrature
{


/**
 * Interface used by all quadrature rules over the square
 **/
class VolumeRule
{
public:
	typedef QuadraturePoint<3> Point;	// helper alias

public:
	virtual ~VolumeRule() {}

	/**
	 * functor that returns the quadrature rule
	 **/
	virtual std::vector<Point> operator() () const = 0;
};


}	// namespace quadrature
}	// namespace fem

#endif // VOLUME_H
