#include <libfemp/mesh/elements/Tetrahedron10.h++>

#include <libfemp/mesh/Node.h++>

fem::mesh::Tetrahedron10::Tetrahedron10(size_t element_id, std::array<std::shared_ptr<fem::mesh::Node>, 10> nodes)
    : Element(element_id)
    , m_nodes(nodes)
{
}

int fem::mesh::Tetrahedron10::getNodeAmount() const
{
    return m_nodes.size();
}

const std::array<std::shared_ptr<fem::mesh::Node>, 10>& fem::mesh::Tetrahedron10::getNodes() const
{
    return m_nodes;
}
