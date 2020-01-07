#ifndef STRESS23_GRADIENT_FIELD_POLICY_H
#define STRESS23_GRADIENT_FIELD_POLICY_H

#include "GradientFieldPolicy.h++"

/**
Stress23 gradient field policy
**/
class Stress23GradientFieldPolicy
    : public GradientFieldPolicy {

protected:
    float val(fem::element_ref_t const& ref, gradient_index_t const& p) const;
    float maxVal(fem::ResultsRanges<double> const&) const;
    float minVal(fem::ResultsRanges<double> const&) const;
};

#endif
