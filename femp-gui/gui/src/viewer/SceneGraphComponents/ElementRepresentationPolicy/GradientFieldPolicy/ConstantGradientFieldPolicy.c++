#include "ConstantGradientFieldPolicy.h++"

#include "../../SceneGraphException.h++"

ConstantGradientFieldPolicy::ConstantGradientFieldPolicy() { this->value = 0; }

float ConstantGradientFieldPolicy::val(fem::element_ref_t const& ref, gradient_index_t const&) const { return this->value; }

float ConstantGradientFieldPolicy::maxVal(fem::ResultsRanges<double> const&) const { return 1; }

float ConstantGradientFieldPolicy::minVal(fem::ResultsRanges<double> const&) const { return -1; }
