#include <libfemp/mesh/elements/Prism18.h++>

#include <libfemp/mesh/Node.h++>

fem::mesh::Prism18::Prism18(size_t element_id, std::array<std::shared_ptr<fem::mesh::Node>, 18> nodes)
    : Element(element_id),
      m_nodes(nodes)
{

}

int fem::mesh::Prism18::getNodeAmount() const
{
    return m_nodes.size();
}

void fem::mesh::Prism18::accept(fem::mesh::ElementVisitor &visitor)
{
    visitor.visit(*this);
}

const std::array<std::shared_ptr<fem::mesh::Node>, 18> &fem::mesh::Prism18::getNodes() const
{
    return m_nodes;
}
