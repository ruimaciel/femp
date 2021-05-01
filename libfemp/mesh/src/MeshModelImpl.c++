#include <libfemp/mesh/MeshModel.h++>

#include "MeshModelImpl.h++"

#include <libfemp/mesh/Element.h++>
#include <libfemp/mesh/Node.h++>

fem::mesh::MeshModelImpl::MeshModelImpl()
{
}

std::shared_ptr<fem::mesh::Node> fem::mesh::MeshModelImpl::getNodeById(size_t nodeId) const
{
    return m_nodeCollection.at(nodeId);
}

size_t fem::mesh::MeshModelImpl::numberOfNodes() const
{
    return this->m_nodeCollection.size();
}

const std::vector<std::shared_ptr<fem::mesh::Node>>& fem::mesh::MeshModelImpl::getNodes() const
{
    return this->m_nodeCollection;
}

size_t fem::mesh::MeshModelImpl::numberOfElements() const
{
    return this->m_elementCollection.size();
}

const std::vector<std::shared_ptr<fem::mesh::Element>>& fem::mesh::MeshModelImpl::getElements() const
{
    return this->m_elementCollection;
}
