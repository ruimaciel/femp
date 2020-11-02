#include "Tetrahedron56.h++"

#include <libfemp/mesh/Node.h++>

fem::mesh::Tetrahedron56::Tetrahedron56(std::array<std::shared_ptr<fem::mesh::Node>, 56> nodes)
    : m_nodes(nodes)
{

}

int fem::mesh::Tetrahedron56::getNodeAmount() const
{
    return m_nodes.size();
}
