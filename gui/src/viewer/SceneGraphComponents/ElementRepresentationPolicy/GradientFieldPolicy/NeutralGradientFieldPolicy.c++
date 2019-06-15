#include "NeutralGradientFieldPolicy.h++"

#include "../../SceneGraphException.h++"

NeutralGradientFieldPolicy::NeutralGradientFieldPolicy()
{
}

float NeutralGradientFieldPolicy::val(fem::element_ref_t const& ref, gradient_index_t const&) const
{
    assert(m_analysis_result != nullptr);
    assert(m_analysis_result->results[ref] != nullptr);
    return 0;
}

float NeutralGradientFieldPolicy::maxVal(fem::ResultsRanges<double> const&) const
{
    return 1;
}

float NeutralGradientFieldPolicy::minVal(fem::ResultsRanges<double> const&) const
{
    return -1;
}
