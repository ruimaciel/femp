#ifndef STRESS13_GRADIENT_FIELD_POLICY_H
#define STRESS13_GRADIENT_FIELD_POLICY_H

#include "GradientFieldPolicy.h++"


/**
Stress13 gradient field policy
**/
class Stress13GradientFieldPolicy
	: public GradientFieldPolicy
{
public:
	Stress13GradientFieldPolicy();

protected:
	float val(fem::element_ref_t const &ref, gradient_index_t const &p);
	float const & maxVal(fem::ResultsRanges<double> const &);
	float const & minVal(fem::ResultsRanges<double> const &);

};


#endif

