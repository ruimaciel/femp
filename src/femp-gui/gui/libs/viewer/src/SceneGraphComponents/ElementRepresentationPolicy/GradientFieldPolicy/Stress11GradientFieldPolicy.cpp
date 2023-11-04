#include "Stress11GradientFieldPolicy.hpp"

#include <assert.h>

#include "../../SceneGraphException.hpp"

float Stress11GradientFieldPolicy::val(fem::element_ref_t const& ref, gradient_index_t const& p) const {
	assert(m_analysis_result != nullptr);
	assert(m_analysis_result->results[ref] != nullptr);
	return this->m_analysis_result->results[ref]->stresses[p].s11;
}

float Stress11GradientFieldPolicy::maxVal(fem::ResultsRanges<double> const& ranges) const {
	return ranges.max_stress11;
}

float Stress11GradientFieldPolicy::minVal(fem::ResultsRanges<double> const& ranges) const {
	return ranges.min_stress11;
}
