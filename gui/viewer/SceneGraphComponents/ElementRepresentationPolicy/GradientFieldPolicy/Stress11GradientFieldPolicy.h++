#ifndef STRESS11_GRADIENT_FIELD_POLICY_H
#define STRESS11_GRADIENT_FIELD_POLICY_H

#include "GradientFieldPolicy.h++"


/**
Stress11 gradient field policy
**/
class Stress11GradientFieldPolicy
	: public GradientFieldPolicy
{
public:
	Stress11GradientFieldPolicy();

protected:
	float val(fem::element_ref_t const &ref, gradient_index_t const &p);
	float maxVal();
	float minVal();

};


#endif

