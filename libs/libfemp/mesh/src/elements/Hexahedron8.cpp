#include <libfemp/mesh/Node.hpp>
#include <libfemp/mesh/elements/Hexahedron8.hpp>

fem::mesh::Hexahedron8::Hexahedron8(size_t element_id, std::array<std::shared_ptr<fem::mesh::Node>, 8> nodes) : Element(element_id), m_nodes(nodes) {}

int fem::mesh::Hexahedron8::getNodeAmount() const {
	return m_nodes.size();
}

void fem::mesh::Hexahedron8::accept(fem::mesh::ElementVisitor& visitor) {
	visitor.visit(*this);
}

const std::array<std::shared_ptr<fem::mesh::Node>, 8>& fem::mesh::Hexahedron8::getNodes() const {
	return m_nodes;
}
