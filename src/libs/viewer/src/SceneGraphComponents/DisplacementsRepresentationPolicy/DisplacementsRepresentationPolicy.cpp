#include "DisplacementsRepresentationPolicy.hpp"

DisplacementsRepresentationPolicy::~DisplacementsRepresentationPolicy() = default;

void DisplacementsRepresentationPolicy::setModel(fem::Model& model) {
	this->m_model = &model;
}