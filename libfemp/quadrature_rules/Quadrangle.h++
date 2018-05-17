#ifndef FEM_QUADRATURE_SQUARE_HPP
#define FEM_QUADRATURE_SQUARE_HPP


#include <memory>
#include <vector>
#include "SurfaceRule.h++"
#include "QuadraturePoint.h++"

#include "Line.h++"

namespace fem
{
namespace quadrature
{


/**
 * Interface used by all quadrature rules over the square
 **/
class QuadrangleRule : public SurfaceRule
{
public:
	typedef QuadraturePoint<2> Point;	// helper alias

public:
	virtual ~QuadrangleRule() {}

	/**
	 * functor that returns the quadrature rule
	 **/
	virtual std::vector<Point> operator() () const = 0;
};



/**
 * Assembles a cubature rule on a quadrangle with a cartesian product of
 * two quadrature rules
 **/
class QuadrangleCartesianProduct
	: public QuadrangleRule
{
private:
	std::unique_ptr<LineRule> m_rule1, m_rule2;

public:
	QuadrangleCartesianProduct(LineRule *rule1, LineRule *rule2);

	virtual std::vector<Point> operator() () const override;
};



}	// namespace quadrature
}	// namespace fem

#endif
