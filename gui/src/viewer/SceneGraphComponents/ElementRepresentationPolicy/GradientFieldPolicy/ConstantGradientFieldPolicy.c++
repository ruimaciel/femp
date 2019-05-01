#include "ConstantGradientFieldPolicy.h++"

#include <iostream>

#include "../../SceneGraphException.h++"


ConstantGradientFieldPolicy::ConstantGradientFieldPolicy()
{
    this->value = 0;
}


float
ConstantGradientFieldPolicy::val(fem::element_ref_t const &ref, gradient_index_t const &) const
{
    assert(m_analysis_result != nullptr);
    assert(m_analysis_result->results[ref] != nullptr);
    return this->value;
}


float
ConstantGradientFieldPolicy::maxVal(fem::ResultsRanges<double> const &) const
{
    return 1;
}


float
ConstantGradientFieldPolicy::minVal(fem::ResultsRanges<double> const &) const
{
    return -1;
}

