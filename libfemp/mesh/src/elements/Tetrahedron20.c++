#include <libfemp/mesh/Node.h++>
#include <libfemp/mesh/elements/Tetrahedron20.h++>

fem::mesh::Tetrahedron20::Tetrahedron20(size_t element_id, std::array<std::shared_ptr<fem::mesh::Node>, 20> nodes) : Element(element_id), m_nodes(nodes) {}

int fem::mesh::Tetrahedron20::getNodeAmount() const { return m_nodes.size(); }

const std::array<std::shared_ptr<fem::mesh::Node>, 20>& fem::mesh::Tetrahedron20::getNodes() const { return m_nodes; }
