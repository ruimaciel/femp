#include "Strain22GradientFieldPolicy.h++"

#include "../../SceneGraphException.h++"

#include <libfemp/Point3D.h++>


float
Strain22GradientFieldPolicy::val(fem::element_ref_t const &ref, gradient_index_t const &p) const
{
    assert(m_analysis_result != nullptr);
    assert(m_analysis_result->results[ref] != nullptr);
    return this->m_analysis_result->results[ref]->strains[p].e22;
}


float
Strain22GradientFieldPolicy::maxVal(fem::ResultsRanges<double> const &ranges) const
{
    return ranges.max_strain22;
}


float
Strain22GradientFieldPolicy::minVal(fem::ResultsRanges<double> const &ranges) const
{
    return ranges.min_strain22;
}

