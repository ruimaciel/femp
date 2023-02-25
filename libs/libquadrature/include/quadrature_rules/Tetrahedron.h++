#ifndef FEM_QUADRATURE_TETRAHEDRON_HPP
#define FEM_QUADRATURE_TETRAHEDRON_HPP

#include <memory>
#include <vector>

#include "Line.h++"
#include "VolumeRule.h++"

namespace fem {
namespace quadrature {

/**
 * Interface used by all quadrature rules over the square
 */
class TetrahedronRule : public VolumeRule {
	public:
	virtual ~TetrahedronRule();

	/**
	 * functor that returns the quadrature rule
	 */
	virtual std::vector<QuadraturePoint> operator()() const = 0;
};

/**
 * 1-point quadrature rule over the unit triangle
 */
class Tetrahedron1 : public TetrahedronRule {
	public:
	virtual std::vector<QuadraturePoint> operator()() const override;
};

/**
 * 4-point quadrature rule over the unit triangle
 */
class Tetrahedron4 : public TetrahedronRule {
	public:
	virtual std::vector<QuadraturePoint> operator()() const override;
};

/**
 * 8-point quadrature rule over the unit triangle
 */
class Tetrahedron8 : public TetrahedronRule {
	public:
	virtual std::vector<QuadraturePoint> operator()() const override;
};

/**
 * 14-point quadrature rule over the unit triangle
 */
class Tetrahedron14 : public TetrahedronRule {
	public:
	virtual std::vector<QuadraturePoint> operator()() const override;
};

}  // namespace quadrature
}  // namespace fem

#endif
