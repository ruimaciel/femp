#include "Hexahedron8.h++"

#include <libfemp/mesh/Node.h++>

fem::mesh::Hexahedron8::Hexahedron8(std::array<std::shared_ptr<fem::mesh::Node>, 8> nodes)
    : m_nodes(nodes)
{

}


int fem::mesh::Hexahedron8::getNodeAmount() const
{
    return m_nodes.size();
}
