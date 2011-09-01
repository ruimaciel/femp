#include "GradientFieldFlyweightFactory.h++"


GradientFieldPolicy * 
GradientFieldFlyweightFactory::neutral()	
{ 
	return &m_neutral_policy; 
}


GradientFieldPolicy * 
GradientFieldFlyweightFactory::constant(float value)	
{ 
	m_constant_policy.value = value; return &m_constantl_policy; 
}


void 
GradientFieldFlyweightFactory::setMaximumGradientValue (float new_maximum)
{
	m_neutral_policy.setMaximumGradientValue(new_maximum);
	m_constant_policy.setMaximumGradientValue(new_maximum);
}


void 
GradientFieldFlyweightFactory::setMinimumGradientValue (float new_minimum)
{
	m_neutral_policy.setMinimumGradientValue(new_minimum);
	m_constant_policy.setMinimumGradientValue(new_minimum);
}


