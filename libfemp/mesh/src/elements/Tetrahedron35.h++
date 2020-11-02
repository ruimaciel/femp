#ifndef FEM_MESH_TETRAHEDRON35_H
#define FEM_MESH_TETRAHEDRON35_H

#include <array>

#include <libfemp/mesh/Element.h++>
#include <libfemp/mesh/Node.h++>

namespace fem {
namespace mesh {

class Tetrahedron35: public Element
{
public:
    Tetrahedron35(std::array<std::shared_ptr<Node>, 35> nodes);

    int getNodeAmount() const override;

private:
    std::array<std::shared_ptr<Node>, 35> m_nodes;
};

} // namespace mesh
} // namespace fem

#endif // FEM_MESH_TETRAHEDRON35_H
