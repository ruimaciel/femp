#include "Tetrahedron4.h++"

#include <libfemp/mesh/Node.h++>

fem::mesh::Tetrahedron4::Tetrahedron4(std::array<std::shared_ptr<fem::mesh::Node>, 4> nodes)
    : m_nodes(nodes)
{

}

int fem::mesh::Tetrahedron4::getNodeAmount() const
{
    return m_nodes.size();
}
