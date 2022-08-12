#include <libfemp/mesh/Node.h++>
#include <libfemp/mesh/elements/Hexahedron20.h++>

fem::mesh::Hexahedron20::Hexahedron20(size_t element_id, std::array<std::shared_ptr<fem::mesh::Node>, 20> nodes) : Element(element_id), m_nodes(nodes) {}

int fem::mesh::Hexahedron20::getNodeAmount() const { return m_nodes.size(); }

void fem::mesh::Hexahedron20::accept(fem::mesh::ElementVisitor& visitor) { visitor.visit(*this); }

const std::array<std::shared_ptr<fem::mesh::Node>, 20>& fem::mesh::Hexahedron20::getNodes() const { return m_nodes; }
