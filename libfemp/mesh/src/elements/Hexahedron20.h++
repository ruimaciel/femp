#ifndef FEM_MESH_HEXAHEDRON20_H
#define FEM_MESH_HEXAHEDRON20_H

#include <array>

#include <libfemp/mesh/Element.h++>
#include <libfemp/mesh/Node.h++>

namespace fem {
namespace mesh {

class Hexahedron20: public Element
{
public:
    Hexahedron20(std::array<std::shared_ptr<Node>, 20> nodes);

    int getNodeAmount() const override;

private:
    std::array<std::shared_ptr<Node>, 20> m_nodes;
};

} // namespace mesh
} // namespace fem

#endif // FEM_MESH_HEXAHEDRON20_H
