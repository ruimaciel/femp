#ifndef FEMP_VIEWER_22_GRADIENT_FIELD_POLICY_HPP
#define FEMP_VIEWER_22_GRADIENT_FIELD_POLICY_HPP

#include "GradientFieldPolicy.hpp"

/**
 * Stress22 gradient field policy
 **/
class Stress22GradientFieldPolicy : public GradientFieldPolicy {
	protected:
	float val(fem::element_ref_t const& ref, gradient_index_t const& p) const;
	float maxVal(fem::ResultsRanges<double> const&) const override;
	float minVal(fem::ResultsRanges<double> const&) const override;
};

#endif
