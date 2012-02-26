#include "ConstantGradientFieldPolicy.h++"

#include <iostream>

#include "../../SceneGraphException.h++"


ConstantGradientFieldPolicy::ConstantGradientFieldPolicy()
{
	this->value = 0;
}


float 
ConstantGradientFieldPolicy::val(fem::element_ref_t const &ref, gradient_index_t const &)
{
	assert(m_analysis_result != NULL);
	assert(m_analysis_result->results[ref] != NULL);
	return this->value;
}


float const & 
ConstantGradientFieldPolicy::maxVal(fem::ResultsRanges<double> const &)
{
	return 1;
}


float const & 
ConstantGradientFieldPolicy::minVal(fem::ResultsRanges<double> const &)
{
	return -1;
}

