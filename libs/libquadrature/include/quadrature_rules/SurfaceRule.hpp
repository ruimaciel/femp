#ifndef SURFACERULE_H
#define SURFACERULE_H

#include <vector>

#include "QuadraturePoint.hpp"

namespace fem {
namespace quadrature {

/**
 * Interface used by all quadrature rules over the square
 **/
class SurfaceRule {
	public:
	using Point = QuadraturePoint<2>;  // helper alias

	public:
	virtual ~SurfaceRule();

	/**
	 * functor that returns the quadrature rule
	 */
	virtual std::vector<Point> operator()() const = 0;
};

}  // namespace quadrature
}  // namespace fem

#endif	// SURFACERULE_H
