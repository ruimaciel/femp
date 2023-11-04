#ifndef GUI_SERVICES_ISELECTIONSERVICE_H
#define GUI_SERVICES_ISELECTIONSERVICE_H

#include <cstddef>
#include <set>

#include "Selection.hpp"

namespace gui {
namespace services {

class ISelectionService {
	public:
	ISelectionService();
	virtual ~ISelectionService() = default;

	virtual Selection getSelection() const = 0;
	virtual std::set<std::size_t> getSelectedElementReferences() const = 0;
	virtual std::set<std::size_t> getSelectedNodeReferences() const = 0;
};

}  // namespace services
}  // namespace gui

#endif	// GUI_SERVICES_ISELECTIONSERVICE_H
