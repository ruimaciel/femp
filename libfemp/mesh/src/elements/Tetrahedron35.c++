#include "Tetrahedron35.h++"

#include <libfemp/mesh/Node.h++>

fem::mesh::Tetrahedron35::Tetrahedron35(std::array<std::shared_ptr<fem::mesh::Node>, 35> nodes)
    : m_nodes(nodes)
{

}

int fem::mesh::Tetrahedron35::getNodeAmount() const
{
    return m_nodes.size();
}
