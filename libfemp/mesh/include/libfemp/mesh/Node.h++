#ifndef FEM_MESH_NODE_H
#define FEM_MESH_NODE_H

#include <array>

namespace fem {
namespace mesh {

class Node {
   public:
	Node(size_t nodeId, std::array<double, 3> coordinates);

	size_t id() const;
	double x() const;
	double y() const;
	double z() const;

   private:
	size_t m_node_id;
	std::array<double, 3> m_coordinates;
};

}  // namespace mesh
}  // namespace fem

#endif	// FEM_MESH_NODE_H
