#ifndef NEUTRAL_GRADIENT_FIELD_POLICY_H
#define NEUTRAL_GRADIENT_FIELD_POLICY_H

#include "GradientFieldPolicy.hpp"

/**
 * Test gradient field policy.  All values are zero
 **/
class NeutralGradientFieldPolicy : public GradientFieldPolicy {
	protected:
	float val(fem::element_ref_t const& ref, gradient_index_t const& p) const;

	float maxVal(fem::ResultsRanges<double> const&) const override;
	float minVal(fem::ResultsRanges<double> const&) const override;
};

#endif
