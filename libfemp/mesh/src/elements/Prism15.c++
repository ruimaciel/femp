#include "Prism15.h++"

#include <libfemp/mesh/Node.h++>

fem::mesh::Prism15::Prism15(std::array<std::shared_ptr<fem::mesh::Node>, 15> nodes)
    : m_nodes(nodes)
{

}

int fem::mesh::Prism15::getNodeAmount() const
{
    return m_nodes.size();
}
