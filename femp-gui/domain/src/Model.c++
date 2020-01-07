#include <Model.h++>

#include "ModelImpl.h++"

namespace gui
{


Model::Model(fem::Model &model)
    : m_impl(new ModelImpl(model))
{

}

Model::~Model()
{

}

std::vector<fem::Element> Model::getElementList() const
{
    return m_impl->getElementList();
}

fem::Element Model::getElementByReference(size_t element_ref) const
{
    return m_impl->getElementByReference(element_ref);
}

size_t Model::getElementSize() const
{
    return m_impl->getElementList().size();
}

std::vector<size_t> Model::getNodeReferenceList() const
{
    return m_impl->getNodeReferenceList();
}

std::map<size_t, fem::Node> Model::getNodeMap() const
{
    return m_impl->getNodeMap();
}

fem::Node Model::getNodeByReference(size_t node_reference) const
{
    return m_impl->getNodeByReference(node_reference);
}

std::vector<fem::NodeGroup> Model::getNodeGroupList() const
{
    return m_impl->getNodeGroupList();
}

std::vector<fem::ElementGroup> Model::getElementGroupList() const
{
    return m_impl->getElementGroupList();
}

std::vector<fem::LoadPattern> Model::getLoadPatternList() const
{
    return m_impl->getLoadPatternList();
}

std::vector<fem::Material> Model::getMaterialList() const
{
    return m_impl->getMaterialList();
}

void Model::pushMaterial(fem::Material new_material)
{
    m_impl->pushMaterial(new_material);
}

std::map<unsigned int, fem::NodeRestrictions> Model::getNodeRestrictions() const
{
    return m_impl->getNodeRestrictions();
}

}	// namespace gui
