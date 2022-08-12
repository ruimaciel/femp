#ifndef STRAIN33_GRADIENT_FIELD_POLICY_H
#define STRAIN33_GRADIENT_FIELD_POLICY_H

#include "GradientFieldPolicy.h++"

/**
 * Strain33 gradient field policy
 **/
class Strain33GradientFieldPolicy : public GradientFieldPolicy {
   protected:
	float val(fem::element_ref_t const& ref, gradient_index_t const& p) const;
	float maxVal(fem::ResultsRanges<double> const&) const;
	float minVal(fem::ResultsRanges<double> const&) const;
};

#endif
