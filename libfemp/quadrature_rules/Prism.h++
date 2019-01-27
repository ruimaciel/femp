#ifndef FEM_QUADRATURE_PRISM_HPP
#define FEM_QUADRATURE_PRISM_HPP


#include <memory>
#include <vector>
#include "VolumeRule.h++"

#include "Line.h++"
#include "Triangle.h++"

namespace fem
{
namespace quadrature
{


/**
 * Interface used by all quadrature rules over the square
 **/
class PrismRule : public VolumeRule
{
public:
	virtual ~PrismRule();

	/**
	 * functor that returns the quadrature rule
	 **/
	virtual std::vector<QuadraturePoint> operator() () const = 0;
};



/**
 * Assembles a cubature rule on a square with a cartesian product of two
 * quadrature rules
 **/
class PrismCartesianProduct
	: public PrismRule
{
private:
	std::unique_ptr<TriangleRule> m_rule_xy;
	std::unique_ptr<LineRule>	m_rule_z;

public:
	PrismCartesianProduct(TriangleRule *rule_xy, LineRule *rule_z);

	virtual std::vector<QuadraturePoint> operator() () const override;
};



}	// namespace quadrature
}	// namespace fem

#endif
