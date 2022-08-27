#ifndef FEMP_POINT2D_HPP
#define FEMP_POINT2D_HPP

#include <array>
#include <libfemp/Point3D.h++>

namespace fem {

/**
 * Represents a point embedded in a 2D space
 */
class Point2D : public Point3D {
	public:
	Point2D(std::array<double, 2>& a);
};

}  // namespace fem
#endif
