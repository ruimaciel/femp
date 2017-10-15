#include "Prism.h++"


namespace fem
{
namespace quadrature
{


PrismCartesianProduct::PrismCartesianProduct(TriangleRule *rule_xy, LineRule *rule_z)
{
	m_rule_xy = std::unique_ptr<TriangleRule>(rule_xy);
	m_rule_z = std::unique_ptr<LineRule>(rule_z);
}


std::vector<PrismRule::Point> 
PrismCartesianProduct::operator() () const
{
	std::vector<PrismRule::Point> cube_rule;

	for(TriangleRule::Point &pxy: (*m_rule_xy)() )
	{
		for(LineRule::Point &pz: (*m_rule_z)() )
		{
			cube_rule.push_back( Point{pxy.weight*pz.weight, {pxy.x[0], pxy.x[1], pz.x[0]}} );
		}
	}

	return cube_rule;
}


}	// namespace quadrature
}	// namespace fem

