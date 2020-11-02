#ifndef FEM_MESH_TETRAHEDRON18_H
#define FEM_MESH_TETRAHEDRON18_H

#include <array>

#include <libfemp/mesh/Element.h++>
#include <libfemp/mesh/Node.h++>

namespace fem {
namespace mesh {

class Prism18: public Element
{
public:
    Prism18(std::array<std::shared_ptr<Node>, 18> nodes);

    int getNodeAmount() const override;

private:
    std::array<std::shared_ptr<Node>, 18> m_nodes;
};

} // namespace mesh
} // namespace fem

#endif // FEM_MESH_TETRAHEDRON18_H
