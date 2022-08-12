#include "Strain33GradientFieldPolicy.h++"

#include <libfemp/Point3D.h++>

#include "../../SceneGraphException.h++"

float Strain33GradientFieldPolicy::val(fem::element_ref_t const& ref, gradient_index_t const& p) const {
	assert(m_analysis_result != nullptr);
	assert(m_analysis_result->results[ref] != nullptr);
	return this->m_analysis_result->results[ref]->strains[p].e33;
}

float Strain33GradientFieldPolicy::maxVal(fem::ResultsRanges<double> const& ranges) const { return ranges.max_strain33; }

float Strain33GradientFieldPolicy::minVal(fem::ResultsRanges<double> const& ranges) const { return ranges.min_strain33; }
