#include <libfemp/mesh/elements/Prism15.h++>

#include <libfemp/mesh/Node.h++>

fem::mesh::Prism15::Prism15(size_t element_id, std::array<std::shared_ptr<fem::mesh::Node>, 15> nodes)
    : Element(element_id),
      m_nodes(nodes)
{

}

int fem::mesh::Prism15::getNodeAmount() const
{
    return m_nodes.size();
}

void fem::mesh::Prism15::accept(fem::mesh::ElementVisitor &visitor)
{
    visitor.visit(*this);
}

const std::array<std::shared_ptr<fem::mesh::Node>, 15> &fem::mesh::Prism15::getNodes() const
{
    return m_nodes;
}
