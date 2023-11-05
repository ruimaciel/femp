#ifndef STRAIN23_GRADIENT_FIELD_POLICY_H
#define STRAIN23_GRADIENT_FIELD_POLICY_H

#include "GradientFieldPolicy.hpp"

/**
 * Strain23 gradient field policy
 **/
class Strain23GradientFieldPolicy : public GradientFieldPolicy {
	protected:
	float val(fem::element_ref_t const& ref, gradient_index_t const& p) const;
	float maxVal(fem::ResultsRanges<double> const&) const override;
	float minVal(fem::ResultsRanges<double> const&) const override;
};

#endif