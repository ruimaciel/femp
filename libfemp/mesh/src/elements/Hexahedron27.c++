#include <libfemp/mesh/elements/Hexahedron27.h++>

#include <libfemp/mesh/Node.h++>

fem::mesh::Hexahedron27::Hexahedron27(size_t element_id, std::array<std::shared_ptr<fem::mesh::Node>, 27> nodes)
    : Element(element_id),
      m_nodes(nodes)
{

}

int fem::mesh::Hexahedron27::getNodeAmount() const
{
    return m_nodes.size();
}

void fem::mesh::Hexahedron27::accept(fem::mesh::ElementVisitor &visitor)
{
    visitor.visit(*this);
}

const std::array<std::shared_ptr<fem::mesh::Node>, 27> &fem::mesh::Hexahedron27::getNodes() const
{
    return m_nodes;
}
