#ifndef FEM_MESH_TETRAHEDRON6_H
#define FEM_MESH_TETRAHEDRON6_H

#include <array>
#include <libfemp/mesh/Element.h++>
#include <libfemp/mesh/Node.h++>

namespace fem {
namespace mesh {

class Prism6 : public Element {
   public:
	Prism6(size_t element_id, std::array<std::shared_ptr<Node>, 6> nodes);

	int getNodeAmount() const override;

	void accept(ElementVisitor& visitor) override;

	const std::array<std::shared_ptr<Node>, 6>& getNodes() const;

   private:
	std::array<std::shared_ptr<Node>, 6> m_nodes;
};

}  // namespace mesh
}  // namespace fem

#endif	// FEM_MESH_TETRAHEDRON6_H
