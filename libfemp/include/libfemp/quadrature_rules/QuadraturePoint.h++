#ifndef FEM_QUADRATURE_POINT_HPP
#define FEM_QUADRATURE_POINT_HPP

#include <array>
#include <cstddef>

namespace fem {
namespace quadrature {

template <size_t D>
struct QuadraturePoint {
    double weight;
    std::array<double, D> x;
};

} // namespace quadrature
} // namespace fem

#endif
