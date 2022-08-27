#include "Stress22GradientFieldPolicy.h++"

#include <assert.h>

#include "../../SceneGraphException.h++"

float Stress22GradientFieldPolicy::val(fem::element_ref_t const& ref, gradient_index_t const& p) const {
	assert(m_analysis_result != nullptr);
	assert(m_analysis_result->results[ref] != nullptr);
	return this->m_analysis_result->results[ref]->stresses[p].s22;
}

float Stress22GradientFieldPolicy::maxVal(fem::ResultsRanges<double> const& ranges) const {
	return ranges.max_stress22;
}

float Stress22GradientFieldPolicy::minVal(fem::ResultsRanges<double> const& ranges) const {
	return ranges.min_stress22;
}
