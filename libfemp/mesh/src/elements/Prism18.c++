#include "Prism18.h++"

#include <libfemp/mesh/Node.h++>

fem::mesh::Prism18::Prism18(std::array<std::shared_ptr<fem::mesh::Node>, 18> nodes)
    : m_nodes(nodes)
{

}

int fem::mesh::Prism18::getNodeAmount() const
{
    return m_nodes.size();
}
