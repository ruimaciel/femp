#ifndef FEM_MESH_HEXAHEDRON27_H
#define FEM_MESH_HEXAHEDRON27_H

#include <array>

#include <libfemp/mesh/Element.h++>
#include <libfemp/mesh/Node.h++>

namespace fem {
namespace mesh {

class Hexahedron27: public Element
{
public:
    Hexahedron27(std::array<std::shared_ptr<Node>, 27> nodes);

    int getNodeAmount() const override;

private:
    std::array<std::shared_ptr<Node>, 27> m_nodes;
};

} // namespace mesh
} // namespace fem

#endif // FEM_MESH_HEXAHEDRON27_H
