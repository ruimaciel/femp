#ifndef FEM_QUADRATURE_CUBE_HPP
#define FEM_QUADRATURE_CUBE_HPP


#include <memory>
#include <vector>
#include "QuadraturePoint.h++"

#include "Line.h++"

namespace fem
{


/**
 * Interface used by all quadrature rules over the square
 **/
class CubeRule
{
public:
	typedef QuadraturePoint<3> Point;	// helper alias

public:
	virtual ~CubeRule() {};
	
	/**
	 * functor that returns the quadrature rule
	 **/
	virtual std::vector<Point> operator() () const = 0;
};



/**
 * Assembles a cubature rule on a square with a cartesian product of two 
 * quadrature rules
 **/
class CubeCartesianProduct
	: public CubeRule
{
private:
	std::unique_ptr<LineRule> m_rule_x, m_rule_y, m_rule_z;

public:
	CubeCartesianProduct(LineRule *rule_x, LineRule *rule_y, LineRule *rule_z);

	virtual std::vector<Point> operator() () const override;
};



}	// namespace fem

#endif
