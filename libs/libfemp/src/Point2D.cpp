#include <libfemp/Point2D.hpp>

fem::Point2D::Point2D(std::array<double, 2>& a) : Point3D(a[0], a[1]) {}
