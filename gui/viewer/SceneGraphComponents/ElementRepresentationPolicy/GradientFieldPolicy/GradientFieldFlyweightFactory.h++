#ifndef GRADIENT_FIELD_FLYWEIGHT_FACTORY_HPP
#define GRADIENT_FIELD_FLYWEIGHT_FACTORY_HPP

#include "GradientFieldPolicy.h++"

#include "NeutralGradientFieldPolicy.h++"
#include "ConstantGradientFieldPolicy.h++"


/**
Flyweight actory pattern to store all gradient field policy classes
**/
class GradientFieldFlyweightFactory
{
protected:
	NeutralGradientFieldPolicy m_neutral_policy;	// test pattern
	ConstantGradientFieldPolicy m_constant_policy;

public:
	GradientFieldPolicy * neutral()	{ return &m_neutral_policy; }
	GradientFieldPolicy * constant(float value)	{ m_constant_policy.value = value; return &m_constantl_policy; }

	void setMaximumGradientValue (float new_maximum);
	void setMinimumGradientValue (float new_minimum);
};

#endif
