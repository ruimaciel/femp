#include <selection/SelectionService.h++>

namespace gui {
namespace services {

SelectionService::SelectionService() {

}

Selection SelectionService::getSelection() const {
    return {};
}

std::set<std::size_t> SelectionService::getSelectedElementReferences() const {
    return {};
}

std::set<std::size_t> SelectionService::getSelectedNodeReferences() const {
    return {};
}

}  // namespace services
}  // namespace gui
