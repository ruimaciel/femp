#ifndef FEM_QUADRATURE_POINT_HPP
#define FEM_QUADRATURE_POINT_HPP


#include <cstddef>
#include <array>



namespace fem
{
namespace quadrature
{


template<size_t D>
struct QuadraturePoint
{
	double weight;
	std::array<double, D> x;
};


}	// namespace quadrature
}	// namespace fem

#endif
