#include "Hexahedron.h++"


namespace fem
{


HexahedronCartesianProduct::HexahedronCartesianProduct(LineRule *rule_x, LineRule *rule_y, LineRule *rule_z)
{
	m_rule_x = std::unique_ptr<LineRule>(rule_x);
	m_rule_y = std::unique_ptr<LineRule>(rule_y);
	m_rule_z = std::unique_ptr<LineRule>(rule_z);
}


std::vector<HexahedronRule::Point> 
HexahedronCartesianProduct::operator() () const
{
	std::vector<HexahedronRule::Point> cube_rule;

	for(LineRule::Point &px: (*m_rule_x)() )
	{
		for(LineRule::Point &py: (*m_rule_y)() )
		{
			
			for(LineRule::Point &pz: (*m_rule_z)() )
			{
				   cube_rule.push_back( Point{px.weight*py.weight*pz.weight, {px.x[0], py.x[0], pz.x[0]}} );
			}
		}
	}

	return cube_rule;
}


}	// namespace fem

