#ifndef FEM_MESH_TETRAHEDRON56_H
#define FEM_MESH_TETRAHEDRON56_H

#include <array>

#include <libfemp/mesh/Element.h++>
#include <libfemp/mesh/Node.h++>

namespace fem {
namespace mesh {

class Tetrahedron56: public Element
{
public:
    Tetrahedron56(std::array<std::shared_ptr<Node>, 56> nodes);

    int getNodeAmount() const override;

private:
    std::array<std::shared_ptr<Node>, 56> m_nodes;
};

} // namespace mesh
} // namespace fem

#endif // FEM_MESH_TETRAHEDRON56_H
