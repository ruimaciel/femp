#include "VonMisesGradientFieldPolicy.h++"

#include <assert.h>

#include "../../SceneGraphException.h++"

float VonMisesGradientFieldPolicy::val(fem::element_ref_t const& ref, gradient_index_t const& p) const
{
    assert(m_analysis_result != nullptr);
    assert(m_analysis_result->results[ref] != nullptr);
    return this->m_analysis_result->results[ref]->von_mises[p];
}

float VonMisesGradientFieldPolicy::maxVal(fem::ResultsRanges<double> const& ranges) const
{
    return ranges.max_von_mises;
}

float VonMisesGradientFieldPolicy::minVal(fem::ResultsRanges<double> const& ranges) const
{
    return ranges.min_von_mises;
}
