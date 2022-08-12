#include <libfemp/mesh/Node.h++>
#include <libfemp/mesh/elements/Tetrahedron35.h++>

fem::mesh::Tetrahedron35::Tetrahedron35(size_t element_id, std::array<std::shared_ptr<fem::mesh::Node>, 35> nodes) : Element(element_id), m_nodes(nodes) {}

int fem::mesh::Tetrahedron35::getNodeAmount() const { return m_nodes.size(); }

const std::array<std::shared_ptr<fem::mesh::Node>, 35>& fem::mesh::Tetrahedron35::getNodes() const { return m_nodes; }
