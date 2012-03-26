#ifndef STRESS_TENSOR_HPP
#define STRESS_TENSOR_HPP

#include <array>

#include <GL/gl.h>
#include "../../../../fem/point.h++"
#include "../../../ViewportColors.h++"


namespace StressFieldRepresentation
{

/**
Renders the three principal directions of a tensor in a point in space
**/
class StressTensor
{
public:
	fem::point 	m_position;	// the position in space where the stress tensor will be rendered
	fem::point 	m_direction[3];	// the three principal directions of a 3D tensor
	float		m_stress[3];	// the stress of each principal direction
	GLfloat		color[3];
	
public:
	/**
	Renders the stress tensor with colors scaled between max and min
	**/
	void render(float const &diameter, float const &max, float const &min, ViewportColors const &colors);

protected:
	void setColor(float const &gradient,  float const &max, float const &min, std::array<GLfloat, 3> &color, ViewportColors const &colors);
};


}

#endif
