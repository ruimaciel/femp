#ifndef NEUTRAL_GRADIENT_FIELD_POLICY_H
#define NEUTRAL_GRADIENT_FIELD_POLICY_H

#include "GradientFieldPolicy.h++"


/**
Test gradient field policy.  All values are zero
**/
class NeutralGradientFieldPolicy
	: public GradientFieldPolicy
{
public:
	NeutralGradientFieldPolicy();

protected:
	/** returns the gradient value for each result
	**/
	float val(fem::element_ref_t const &ref, gradient_index_t const &p);
	float const & maxVal(fem::ResultsRanges<double> const &);
	float const & minVal(fem::ResultsRanges<double> const &);


};


#endif

