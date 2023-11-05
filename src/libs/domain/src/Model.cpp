#include <domain/Model.hpp>

#include "ModelImpl.hpp"

domain::Model::Model(fem::Model& model) : m_impl(new ModelImpl(model)) {}

domain::Model::~Model() {}

std::vector<fem::Element> domain::Model::getElementList() const {
	return m_impl->getElementList();
}

fem::Element domain::Model::getElementByReference(size_t element_ref) const {
	return m_impl->getElementByReference(element_ref);
}

size_t domain::Model::getElementSize() const {
	return m_impl->getElementList().size();
}

std::vector<size_t> domain::Model::getNodeReferenceList() const {
	return m_impl->getNodeReferenceList();
}

std::map<size_t, fem::Node> domain::Model::getNodeMap() const {
	return m_impl->getNodeMap();
}

fem::Node domain::Model::getNodeByReference(size_t node_reference) const {
	return m_impl->getNodeByReference(node_reference);
}

std::vector<fem::NodeGroup> domain::Model::getNodeGroupList() const {
	return m_impl->getNodeGroupList();
}

std::vector<fem::ElementGroup> domain::Model::getElementGroupList() const {
	return m_impl->getElementGroupList();
}

std::vector<fem::LoadPattern> domain::Model::getLoadPatternList() const {
	return m_impl->getLoadPatternList();
}

std::vector<fem::Material> domain::Model::getMaterialList() const {
	return m_impl->getMaterialList();
}

void domain::Model::pushMaterial(fem::Material new_material) {
	m_impl->pushMaterial(new_material);
}

std::map<unsigned int, fem::NodeRestrictions> domain::Model::getNodeRestrictions() const {
	return m_impl->getNodeRestrictions();
}
