#ifndef FEMP_MESH_MESHMODELIMPL_H
#define FEMP_MESH_MESHMODELIMPL_H

#include <memory>
#include <vector>

#include <libfemp/mesh/MeshModel.h++>

namespace fem {
namespace mesh {

    class Element;
    class Node;

    class MeshModelImpl : public MeshModel {
    public:
        MeshModelImpl();

        std::shared_ptr<Node> getNodeById(size_t nodeId) const override;
        size_t numberOfNodes() const override;
        const std::vector<std::shared_ptr<fem::mesh::Node>>& getNodes() const override;

        size_t numberOfElements() const override;
        const std::vector<std::shared_ptr<Element>>& getElements() const;

    private:
        std::vector<std::shared_ptr<Element>> m_elementCollection;
        std::vector<std::shared_ptr<Node>> m_nodeCollection;
    };

} // namespace mesh
} // namespace fem

#endif // FEMP_MESH_MESHMODELIMPL_H
