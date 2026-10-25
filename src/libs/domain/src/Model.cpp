#include <domain/Model.hpp>

#include "ModelImpl.hpp"

femp::domain::Model::Model(fem::Model &model)
    : m_impl(new femp::domain::ModelImpl(model)) {}

femp::domain::Model::~Model() {}

std::vector<fem::Element> femp::domain::Model::getElementList() const {
  return m_impl->getElementList();
}

fem::Element femp::domain::Model::getElementByReference(size_t element_ref) const {
  return m_impl->getElementByReference(element_ref);
}

size_t femp::domain::Model::getElementSize() const {
  return m_impl->getElementList().size();
}

std::vector<size_t> femp::domain::Model::getNodeReferenceList() const {
  return m_impl->getNodeReferenceList();
}

std::map<size_t, fem::Node> femp::domain::Model::getNodeMap() const {
  return m_impl->getNodeMap();
}

fem::Node femp::domain::Model::getNodeByReference(size_t node_reference) const {
  return m_impl->getNodeByReference(node_reference);
}

std::vector<fem::NodeGroup> femp::domain::Model::getNodeGroupList() const {
  return m_impl->getNodeGroupList();
}

std::vector<fem::ElementGroup> femp::domain::Model::getElementGroupList() const {
  return m_impl->getElementGroupList();
}

std::vector<fem::LoadPattern> femp::domain::Model::getLoadPatternList() const {
  return m_impl->getLoadPatternList();
}

std::vector<fem::Material> femp::domain::Model::getMaterialList() const {
  return m_impl->getMaterialList();
}

void femp::domain::Model::pushMaterial(fem::Material new_material) {
  m_impl->pushMaterial(new_material);
}

std::map<unsigned int, fem::NodeRestrictions>
femp::domain::Model::getNodeRestrictions() const {
  return m_impl->getNodeRestrictions();
}
