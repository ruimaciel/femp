#ifndef FEM_MESH_ELEMENT_H
#define FEM_MESH_ELEMENT_H

#include <memory>
#include <vector>

namespace fem {
namespace mesh {

class Element
{
public:
    virtual ~Element() = default;

    virtual int getNodeAmount() const = 0;
};

} // namespace mesh
} // namespace fem

#endif // FEM_MESH_ELEMENT_H
