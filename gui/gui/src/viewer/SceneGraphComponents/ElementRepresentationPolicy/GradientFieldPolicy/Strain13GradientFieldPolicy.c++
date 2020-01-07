#include "Strain13GradientFieldPolicy.h++"

#include "../../SceneGraphException.h++"

#include <libfemp/Point3D.h++>

float Strain13GradientFieldPolicy::val(fem::element_ref_t const& ref, gradient_index_t const& p) const
{
    assert(m_analysis_result != nullptr);
    assert(m_analysis_result->results[ref] != nullptr);
    return this->m_analysis_result->results[ref]->strains[p].e13;
}

float Strain13GradientFieldPolicy::maxVal(fem::ResultsRanges<double> const& ranges) const
{
    return ranges.max_strain13;
}

float Strain13GradientFieldPolicy::minVal(fem::ResultsRanges<double> const& ranges) const
{
    return ranges.min_strain13;
}
