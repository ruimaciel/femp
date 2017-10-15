#ifndef FEM_QUADRATURE_SQUARE_HPP
#define FEM_QUADRATURE_SQUARE_HPP


#include <memory>
#include <vector>
#include "QuadraturePoint.h++"

#include "Line.h++"

namespace fem
{


/**
 * Interface used by all quadrature rules over the square
 **/
class SquareRule
{
public:
	typedef QuadraturePoint<2> Point;	// helper alias

public:
	virtual ~SquareRule() {};
	
	/**
	 * functor that returns the quadrature rule
	 **/
	virtual std::vector<Point> operator() () const = 0;
};



/**
 * Assembles a cubature rule on a square with a cartesian product of two 
 * quadrature rules
 **/
class SquareCartesianProduct
	: public SquareRule
{
private:
	std::unique_ptr<LineRule> m_rule1, m_rule2;

public:
	SquareCartesianProduct(LineRule *rule1, LineRule *rule2);

	virtual std::vector<Point> operator() () const override;
};



}	// namespace fem

#endif
