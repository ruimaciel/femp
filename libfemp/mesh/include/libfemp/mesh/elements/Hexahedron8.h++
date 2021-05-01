#ifndef FEM_MESH_HEXAHEDRON8_H
#define FEM_MESH_HEXAHEDRON8_H

#include <array>

#include <libfemp/mesh/Element.h++>
#include <libfemp/mesh/Node.h++>

namespace fem {
namespace mesh {

    class Hexahedron8 : public Element {
    public:
        Hexahedron8(size_t element_id, std::array<std::shared_ptr<Node>, 8> nodes);

        int getNodeAmount() const override;

        void accept(ElementVisitor& visitor) override;

        const std::array<std::shared_ptr<Node>, 8>& getNodes() const;

    private:
        std::array<std::shared_ptr<Node>, 8> m_nodes;
    };

} // namespace mesh
} // namespace fem

#endif // FEM_MESH_HEXAHEDRON8_H
