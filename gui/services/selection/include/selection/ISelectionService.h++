#ifndef GUI_SERVICES_ISELECTIONSERVICE_H
#define GUI_SERVICES_ISELECTIONSERVICE_H

#include <set>

namespace gui {
namespace services {

class ISelectionService
{
public:
    ISelectionService();
    virtual ~ISelectionService() = default;

    virtual std::set<size_t> getSelectedElementReferences() const = 0;
    virtual std::set<size_t> getSelectedNodeReferences() const = 0;
};

} // namespace services
} // namespace gui

#endif // GUI_SERVICES_ISELECTIONSERVICE_H
