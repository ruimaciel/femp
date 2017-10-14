#ifndef FEM_QUADRATURE_POINT_HPP
#define FEM_QUADRATURE_POINT_HPP


#include <cstddef>
#include <array>



namespace fem
{


template<size_t D>
struct QuadraturePoint
{
	double weight;
	std::array<double, D> x;
};


}	// namespace fem

#endif
