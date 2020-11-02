#include "Prism6.h++"

#include <libfemp/mesh/Node.h++>

fem::mesh::Prism6::Prism6(std::array<std::shared_ptr<fem::mesh::Node>, 6> nodes)
    : m_nodes(nodes)
{

}

int fem::mesh::Prism6::getNodeAmount() const
{
    return m_nodes.size();
}
