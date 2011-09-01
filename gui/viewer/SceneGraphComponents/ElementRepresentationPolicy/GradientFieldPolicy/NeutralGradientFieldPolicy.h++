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

	void calculateGradientValues (fem::Element &element);
};


#endif

