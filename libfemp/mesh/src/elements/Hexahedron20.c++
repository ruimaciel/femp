#include "Hexahedron20.h++"

#include <libfemp/mesh/Node.h++>

fem::mesh::Hexahedron20::Hexahedron20(std::array<std::shared_ptr<fem::mesh::Node>, 20> nodes)
    : m_nodes(nodes)
{

}

int fem::mesh::Hexahedron20::getNodeAmount() const
{
    m_nodes.size();
}
