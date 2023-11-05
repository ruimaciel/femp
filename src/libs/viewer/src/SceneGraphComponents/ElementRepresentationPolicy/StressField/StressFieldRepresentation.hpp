#ifndef FEMP_VIEWER_STRESSFIELDREPRESENTATION_HPP
#define FEMP_VIEWER_STRESSFIELDREPRESENTATION_HPP

#include <array>
#include <libfemp/Point3D.hpp>
#include <options/Options.hpp>
#include <tuple>
#include <vector>

#include "StressTensor.hpp"

namespace StressFieldRepresentation {

/**
 * Class intended to be a placeholder for a finite set of tensor representations
 *used to represent tensor fields
 **/
class StressFieldRepresentation {
	protected:
	std::vector<StressTensor> m_tensor;

	public:
	/**
	 * Renders this stress field, representing a given element
	 **/
	void render(float const& diameter, float const& max, float const& min, bool const& render_positive, bool const& render_negative,
				ViewportColors const& colors) const;

	/**
	 * Pushes a new tensor to this representation
	 **/
	void push(fem::Point3D const& pos, std::array<fem::Point3D, 3> const& directions, std::array<float, 3> const& stresses);
};
}  // namespace StressFieldRepresentation

#endif
