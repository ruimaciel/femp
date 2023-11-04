#include <libfemp/mesh/Node.hpp>

namespace fem {
namespace mesh {

Node::Node(size_t node_id, std::array<double, 3> coordinates) : m_node_id(node_id), m_coordinates(coordinates) {}

size_t Node::id() const {
	return m_node_id;
}

double Node::x() const {
	return m_coordinates.at(0);
}

double Node::y() const {
	return m_coordinates.at(1);
}

double Node::z() const {
	return m_coordinates.at(2);
}

}  // namespace mesh
}  // namespace fem
