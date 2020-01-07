#include "ModelImpl.h++"

namespace gui {

ModelImpl::ModelImpl(fem::Model &model)
    : m_model(model)
{

}

std::vector<fem::Element> ModelImpl::getElementList() const
{
    return m_model.getElementList();
}

fem::Element ModelImpl::getElementByReference(size_t element_ref) const
{
    return m_model.getElementByIndex(element_ref);
}

std::vector<size_t> ModelImpl::getNodeReferenceList() const
{
    std::vector<size_t> node_references;


    auto node_map = m_model.getNodeMap();

    auto oper = [](const std::pair<size_t, fem::Node> &node) -> size_t
    {
        return node.first;
    };

    std::transform(node_map.begin(), node_map.end(), std::back_inserter(node_references), oper );

    return node_references;
}

std::map<size_t, fem::Node> ModelImpl::getNodeMap() const
{
    return m_model.getNodeMap();
}

fem::Node ModelImpl::getNodeByReference(size_t node_reference) const
{
    return m_model.getNode(node_reference);
}

std::vector<fem::NodeGroup> ModelImpl::getNodeGroupList() const
{
    return m_model.getNodeGroups();
}

std::vector<fem::ElementGroup> ModelImpl::getElementGroupList() const
{
    return m_model.getElementGroups();
}

std::vector<fem::LoadPattern> ModelImpl::getLoadPatternList() const
{
    return m_model.getLoadPatternList();
}

std::vector<fem::Material> ModelImpl::getMaterialList() const
{
    return m_model.getMaterialList();
}

void ModelImpl::pushMaterial(fem::Material new_material)
{
    m_model.pushMaterial(new_material);
}

std::map<unsigned int, fem::NodeRestrictions> ModelImpl::getNodeRestrictions() const
{
    return m_model.getNodeRestrictions();
}

} // namespace gui
