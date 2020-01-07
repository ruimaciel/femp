#ifndef GUI_APPLICATION_INODEREPOSITORY_H
#define GUI_APPLICATION_INODEREPOSITORY_H

#include <vector>
#include <map>
#include <memory>

#include <libfemp/Node.h++>

namespace gui {
namespace application {

class INodeRepository
{
public:
    INodeRepository();

    virtual ~INodeRepository() = default;

    virtual std::vector<size_t> getNodeReferenceList() const = 0;
    virtual std::map<size_t, fem::Node> getNodeMap() const = 0;
    virtual fem::Node getNodeById(size_t node_id) const = 0;
    virtual size_t getNodeSize() const = 0;
};

using INodeRepositoryPtr = std::shared_ptr<INodeRepository>;

} // namespace application
} // namespace gui

#endif // GUI_APPLICATION_INODEREPOSITORY_H
