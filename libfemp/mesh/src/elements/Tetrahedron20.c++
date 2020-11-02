#include "Tetrahedron10.h++"

#include <libfemp/mesh/Node.h++>

fem::mesh::Tetrahedron10::Tetrahedron10(std::array<std::shared_ptr<fem::mesh::Node>, 10> nodes)
    : m_nodes(nodes)
{

}

int fem::mesh::Tetrahedron10::getNodeAmount() const
{
    return m_nodes.size();
}
