#ifndef FEMP_MESH_MESHMODEL_H
#define FEMP_MESH_MESHMODEL_H

#include <memory>
#include <vector>

namespace fem {
namespace mesh {

class Element;
class Node;

class MeshModel
{
public:
    virtual ~MeshModel() = default;

    virtual std::shared_ptr<fem::mesh::Node> getNodeById(size_t nodeId) const = 0;
    virtual size_t numberOfNodes() const = 0;
    virtual const std::vector<std::shared_ptr<fem::mesh::Node>> & getNodes() const = 0;

    virtual size_t numberOfElements() const = 0;
    virtual const std::vector<std::shared_ptr<fem::mesh::Element>> & getElements() const = 0;
};

} 	// namespace mesh
}	// namespace fem

#endif // FEMP_MESHMODEL_H
