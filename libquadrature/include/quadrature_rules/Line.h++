#ifndef FEM_QUADRATURE_LINE_HPP
#define FEM_QUADRATURE_LINE_HPP

#include <vector>

#include "QuadraturePoint.h++"

namespace fem {
namespace quadrature {

/**
 * Interface used by all line rules
 */
class LineRule {
	public:
	using Point = QuadraturePoint<1>;  // helper alias

	public:
	virtual ~LineRule();

	/**
	 * functor that returns the quadrature rule
	 */
	virtual std::vector<Point> operator()() const = 0;
};

/**
 * One point Gauss-Legendre
 */
class GaussLegendre1 : public LineRule {
	public:
	virtual std::vector<Point> operator()() const override;
};

/**
 * two-point Gauss-Legendre
 */
class GaussLegendre2 : public LineRule {
	public:
	virtual std::vector<Point> operator()() const override;
};

/**
 * three-point Gauss-Legendre
 */
class GaussLegendre3 : public LineRule {
	public:
	virtual std::vector<Point> operator()() const override;
};

/**
 * three-point Simpson's rule
 */
class Simpson : public LineRule {
	public:
	virtual std::vector<Point> operator()() const override;
};

}  // namespace quadrature
}  // namespace fem

#endif
