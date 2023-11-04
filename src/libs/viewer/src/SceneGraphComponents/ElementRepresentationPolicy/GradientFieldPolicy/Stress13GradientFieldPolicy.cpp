#include "Stress13GradientFieldPolicy.hpp"

#include <assert.h>

#include "../../SceneGraphException.hpp"

float Stress13GradientFieldPolicy::val(fem::element_ref_t const& ref, gradient_index_t const& p) const {
	assert(m_analysis_result != nullptr);
	assert(m_analysis_result->results[ref] != nullptr);
	return this->m_analysis_result->results[ref]->stresses[p].s13;
}

float Stress13GradientFieldPolicy::maxVal(fem::ResultsRanges<double> const& ranges) const {
	return ranges.max_stress13;
}

float Stress13GradientFieldPolicy::minVal(fem::ResultsRanges<double> const& ranges) const {
	return ranges.min_stress13;
}
