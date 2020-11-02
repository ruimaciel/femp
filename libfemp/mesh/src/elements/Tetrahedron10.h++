#ifndef FEM_MESH_TETRAHEDRON10_H
#define FEM_MESH_TETRAHEDRON10_H

#include <array>

#include <libfemp/mesh/Element.h++>
#include <libfemp/mesh/Node.h++>

namespace fem {
namespace mesh {

class Tetrahedron10: public Element
{
public:
    Tetrahedron10(std::array<std::shared_ptr<Node>, 10> nodes);

    int getNodeAmount() const override;

private:
    std::array<std::shared_ptr<Node>, 10> m_nodes;
};

} // namespace mesh
} // namespace fem

#endif // FEM_MESH_TETRAHEDRON10_H
