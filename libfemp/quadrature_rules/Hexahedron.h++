#ifndef FEM_QUADRATURE_HEXAHEDRON_HPP
#define FEM_QUADRATURE_HEXAHEDRON_HPP


#include <memory>
#include <vector>
#include "QuadraturePoint.h++"

#include "Line.h++"

namespace fem
{


/**
 * Interface used by all quadrature rules over the square
 **/
class HexahedronRule
{
public:
	typedef QuadraturePoint<3> Point;	// helper alias

public:
	virtual ~HexahedronRule() {};
	
	/**
	 * functor that returns the quadrature rule
	 **/
	virtual std::vector<Point> operator() () const = 0;
};



/**
 * Assembles a cubature rule on a square with a cartesian product of two 
 * quadrature rules
 **/
class HexahedronCartesianProduct
	: public HexahedronRule
{
private:
	std::unique_ptr<LineRule> m_rule_x, m_rule_y, m_rule_z;

public:
	HexahedronCartesianProduct(LineRule *rule_x, LineRule *rule_y, LineRule *rule_z);

	virtual std::vector<Point> operator() () const override;
};



}	// namespace fem

#endif
