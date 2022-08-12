#include "DisplacementsPolicy.h++"

// Constructors/Destructors
//

DisplacementsPolicy::DisplacementsPolicy() : DisplacementsRepresentationPolicy() { this->m_result = nullptr; }

DisplacementsPolicy::~DisplacementsPolicy() {}

fem::Point3D DisplacementsPolicy::operator[](size_t& node_reference) {
	assert(this->m_model != nullptr);
	assert(this->m_result != nullptr);

	return this->m_model->getNode(node_reference) + m_scale * this->m_result->displacements[node_reference];
}

void DisplacementsPolicy::setAnalysisResult(fem::AnalysisResult& result) { this->m_result = &result; }

void DisplacementsPolicy::setDisplacementsScale(float scale) {
	assert(scale >= 0);

	this->m_scale = scale;
}
