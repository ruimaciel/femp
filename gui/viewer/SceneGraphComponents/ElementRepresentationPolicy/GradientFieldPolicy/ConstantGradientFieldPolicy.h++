#ifndef MAXIMUM_POSITIVE_GRADIENT_FIELD_POLICY_H
#define MAXIMUM_POSITIVE_GRADIENT_FIELD_POLICY_H

#include "GradientFieldPolicy.h++"


/**
Test gradient field policy.  All values are constant
**/
class ConstantGradientFieldPolicy
	: public GradientFieldPolicy
{
public:
	float value;	// value which is set in all nodes

public:
	ConstantGradientFieldPolicy();
	
protected:
	/** returns the gradient value for each result
	**/
	float val(fem::element_ref_t const &ref, gradient_index_t const &p);

};


#endif

