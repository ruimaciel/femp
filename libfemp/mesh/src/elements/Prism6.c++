#include <libfemp/mesh/elements/Prism6.h++>

#include <libfemp/mesh/Node.h++>

fem::mesh::Prism6::Prism6(size_t element_id, std::array<std::shared_ptr<fem::mesh::Node>, 6> nodes)
    : Element(element_id)
    , m_nodes(nodes)
{
}

int fem::mesh::Prism6::getNodeAmount() const
{
    return m_nodes.size();
}

const std::array<std::shared_ptr<fem::mesh::Node>, 6>& fem::mesh::Prism6::getNodes() const
{
    return m_nodes;
}
