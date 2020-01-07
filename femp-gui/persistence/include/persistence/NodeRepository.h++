#ifndef GUI_PERSISTENCE_NODEREPOSITORY_H
#define GUI_PERSISTENCE_NODEREPOSITORY_H

#include <application/interfaces/INodeRepository.h++>

#include <Model.h++>
#include <memory>

namespace gui {
namespace persistence {

class NodeRepository : public application::INodeRepository
{
public:
    NodeRepository(std::shared_ptr<gui::Model> model);

    // INodeRepository interface
public:
    std::vector<size_t> getNodeReferenceList() const override;
    std::map<size_t, fem::Node> getNodeMap() const override;
    fem::Node getNodeById(size_t node_id) const override;
    size_t getNodeSize() const override;

private:
    std::shared_ptr<gui::Model> m_domain_model;
};

} // namespace persistence
} // namespace gui

#endif // GUI_PERSISTENCE_NODEREPOSITORY_H
