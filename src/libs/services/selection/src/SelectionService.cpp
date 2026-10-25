#include <selection/SelectionService.hpp>

namespace femp::services {

SelectionService::SelectionService() {}

Selection SelectionService::getSelection() const { return {}; }

std::set<std::size_t> SelectionService::getSelectedElementReferences() const {
  return {};
}

std::set<std::size_t> SelectionService::getSelectedNodeReferences() const {
  return {};
}

} // namespace femp::services
