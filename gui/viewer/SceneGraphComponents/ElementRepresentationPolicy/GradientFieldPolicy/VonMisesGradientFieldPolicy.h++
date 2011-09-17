#ifndef VON_MISES_GRADIENT_FIELD_POLICY_H
#define VON_MISES_GRADIENT_FIELD_POLICY_H

#include "GradientFieldPolicy.h++"


/**
Stress11 gradient field policy
**/
class VonMisesGradientFieldPolicy
	: public GradientFieldPolicy
{
public:
	VonMisesGradientFieldPolicy();

protected:
	float val(fem::element_ref_t const &ref, gradient_index_t const &p);
	float const & maxVal(fem::ResultsRanges<double> const &);
	float const & minVal(fem::ResultsRanges<double> const &);

};


#endif

