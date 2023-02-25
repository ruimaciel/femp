#ifndef FEM_MESH_TETRAHEDRON18_H
#define FEM_MESH_TETRAHEDRON18_H

#include <array>
#include <libfemp/mesh/Element.h++>
#include <libfemp/mesh/Node.h++>

namespace fem {
namespace mesh {

class Prism18 : public Element {
	public:
	Prism18(size_t element_id, std::array<std::shared_ptr<Node>, 18> nodes);

	int getNodeAmount() const override;

	void accept(ElementVisitor& visitor) override;

	const std::array<std::shared_ptr<Node>, 18>& getNodes() const;

	private:
	std::array<std::shared_ptr<Node>, 18> m_nodes;
};

}  // namespace mesh
}  // namespace fem

#endif	// FEM_MESH_TETRAHEDRON18_H
