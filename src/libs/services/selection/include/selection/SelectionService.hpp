#ifndef FEMP_SERVICES_SELECTIONSERVICE_HPP
#define FEMP_SERVICES_SELECTIONSERVICE_HPP

#include <cstddef>
#include <selection/ISelectionService.hpp>

namespace femp::services {

/**
 * @brief The SelectionService class provides interfaces to get the references
 * of all elements and nodes which are currently selected.
 */
class SelectionService final : public ISelectionService {
public:
  SelectionService();

  Selection getSelection() const override;
  std::set<std::size_t> getSelectedElementReferences() const override;
  std::set<std::size_t> getSelectedNodeReferences() const override;
};

} // namespace femp::services

#endif // FEMP_SERVICES_SELECTIONSERVICE_HPP
