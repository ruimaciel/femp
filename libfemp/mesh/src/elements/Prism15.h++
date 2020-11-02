#ifndef FEM_MESH_TETRAHEDRON15_H
#define FEM_MESH_TETRAHEDRON15_H

#include <array>

#include <libfemp/mesh/Element.h++>
#include <libfemp/mesh/Node.h++>

namespace fem {
namespace mesh {

class Prism15: public Element
{
public:
    Prism15(std::array<std::shared_ptr<Node>, 15> nodes);

    int getNodeAmount() const override;

private:
    std::array<std::shared_ptr<Node>, 15> m_nodes;
};

} // namespace mesh
} // namespace fem

#endif // FEM_MESH_TETRAHEDRON15_H
