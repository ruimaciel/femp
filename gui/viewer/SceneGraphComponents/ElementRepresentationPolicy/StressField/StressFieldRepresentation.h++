#ifndef STRESS_FIELD_REPRESENTATION_H
#define STRESS_FIELD_REPRESENTATION_H

#include <array>
#include <tuple>
#include <vector>

#include <libfemp/Point.h++>

#include <gui/options/Options.h++>

#include "StressTensor.h++"


namespace StressFieldRepresentation
{

/**
Class intended to be a placeholder for a finite set of tensor representations used to represent tensor fields
**/
class StressFieldRepresentation
{
protected:
	std::vector<StressTensor> m_tensor;

public:
	/**
	Renders this stress field, representing a given element
	**/
	void render(float const & diameter, float const &max, float const &min,  bool const &render_positive, bool const &render_negative,ViewportColors const &colors) const;

	/**
	Pushes a new tensor to this representation
	**/
	void push(fem::Point const &pos, std::array<fem::Point,3> const &directions, std::array<float,3> const &stresses);
};

}

#endif

