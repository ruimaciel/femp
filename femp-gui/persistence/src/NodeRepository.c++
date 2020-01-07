#include <persistence/NodeRepository.h++>

namespace gui {
namespace persistence {

NodeRepository::NodeRepository(std::shared_ptr<gui::Model> model)
    : m_domain_model(model)
{

}

std::vector<size_t> gui::persistence::NodeRepository::getNodeReferenceList() const
{
    return m_domain_model->getNodeReferenceList();
}

std::map<size_t, fem::Node> NodeRepository::getNodeMap() const
{
    return m_domain_model->getNodeMap();
}

fem::Node NodeRepository::getNodeById(size_t node_id) const
{
    return m_domain_model->getNodeByReference(node_id);
}

size_t NodeRepository::getNodeSize() const
{
    return getNodeReferenceList().size();
}

} // namespace persistence
} // namespace gui
