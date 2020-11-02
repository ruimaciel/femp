#include "Hexahedron27.h++"

#include <libfemp/mesh/Node.h++>

fem::mesh::Hexahedron27::Hexahedron27(std::array<std::shared_ptr<fem::mesh::Node>, 27> nodes)
    : m_nodes(nodes)
{

}


int fem::mesh::Hexahedron27::getNodeAmount() const
{
    return m_nodes.size();
}
