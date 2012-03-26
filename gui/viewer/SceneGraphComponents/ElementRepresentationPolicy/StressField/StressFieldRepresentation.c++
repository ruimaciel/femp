#include "StressFieldRepresentation.h++"


namespace StressFieldRepresentation
{


void 
StressFieldRepresentation::render(float const & diameter, float const &max, float const &min, ViewportColors const &colors) const
{
	for(auto tensor: m_tensor)
	{
		tensor.render(diameter, max, min, colors);
	}
}


void 
StressFieldRepresentation::push(fem::point const &pos, std::array<fem::point,3> const &directions, std::array<float,3> const &stresses)
{
	StressTensor tensor;

	tensor.m_position = pos;
	tensor.m_direction[0] = directions[0];
	tensor.m_direction[1] = directions[1];
	tensor.m_direction[2] = directions[2];

	tensor.m_stress[0] = stresses[0];
	tensor.m_stress[1] = stresses[1];
	tensor.m_stress[2] = stresses[2];
}


}

