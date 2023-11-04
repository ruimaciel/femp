#ifndef GUI_SERVICES_SELECTIONSERVICE_H
#define GUI_SERVICES_SELECTIONSERVICE_H

#include <cstddef>
#include <selection/ISelectionService.hpp>

namespace gui {
namespace services {

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

}  // namespace services
}  // namespace gui

#endif	// GUI_SERVICES_SELECTIONSERVICE_H
