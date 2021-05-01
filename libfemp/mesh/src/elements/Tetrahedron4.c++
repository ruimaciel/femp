#include <libfemp/mesh/elements/Tetrahedron4.h++>

#include <libfemp/mesh/Node.h++>

fem::mesh::Tetrahedron4::Tetrahedron4(size_t element_id, std::array<std::shared_ptr<fem::mesh::Node>, 4> nodes)
    : Element(element_id)
    , m_nodes(nodes)
{
}

int fem::mesh::Tetrahedron4::getNodeAmount() const
{
    return m_nodes.size();
}

const std::array<std::shared_ptr<fem::mesh::Node>, 4>& fem::mesh::Tetrahedron4::getNodes() const
{
    return m_nodes;
}
