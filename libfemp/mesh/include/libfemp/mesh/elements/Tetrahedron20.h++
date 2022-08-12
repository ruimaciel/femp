#ifndef FEM_MESH_TETRAHEDRON20_H
#define FEM_MESH_TETRAHEDRON20_H

#include <array>
#include <libfemp/mesh/Element.h++>
#include <libfemp/mesh/Node.h++>

namespace fem {
namespace mesh {

class Tetrahedron20 : public Element {
   public:
	Tetrahedron20(size_t element_id, std::array<std::shared_ptr<Node>, 20> nodes);

	int getNodeAmount() const override;

	void accept(ElementVisitor& visitor) override;

	const std::array<std::shared_ptr<Node>, 20>& getNodes() const;

   private:
	std::array<std::shared_ptr<Node>, 20> m_nodes;
};

}  // namespace mesh
}  // namespace fem

#endif	// FEM_MESH_TETRAHEDRON10_H
