#ifndef FEM_MESH_TETRAHEDRON4_H
#define FEM_MESH_TETRAHEDRON4_H

#include <array>

#include <libfemp/mesh/Element.h++>
#include <libfemp/mesh/Node.h++>

namespace fem {
namespace mesh {

class Tetrahedron4: public Element
{
public:
    Tetrahedron4(std::array<std::shared_ptr<Node>, 4> nodes);

    int getNodeAmount() const override;

private:
    std::array<std::shared_ptr<Node>, 4> m_nodes;
};

} // namespace mesh
} // namespace fem

#endif // FEM_MESH_TETRAHEDRON4_H
