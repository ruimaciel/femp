#include <libfemp/mesh/elements/Tetrahedron56.h++>

#include <libfemp/mesh/Node.h++>

fem::mesh::Tetrahedron56::Tetrahedron56(size_t element_id, std::array<std::shared_ptr<fem::mesh::Node>, 56> nodes)
    : Element(element_id),
      m_nodes(nodes)
{

}

int fem::mesh::Tetrahedron56::getNodeAmount() const
{
    return m_nodes.size();
}

const std::array<std::shared_ptr<fem::mesh::Node>, 56> &fem::mesh::Tetrahedron56::getNodes() const
{
    return m_nodes;
}
