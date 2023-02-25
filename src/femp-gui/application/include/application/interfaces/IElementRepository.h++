#ifndef GUI_APPLICATION_IELEMENTREPOSITORY_H
#define GUI_APPLICATION_IELEMENTREPOSITORY_H

#include <libfemp/Element.h++>
#include <memory>

namespace gui {
namespace application {

class IElementRepository {
	public:
	IElementRepository();

	virtual ~IElementRepository();

	virtual std::vector<fem::Element> getElementList() const = 0;

	virtual fem::Element getElementById(size_t element_id) const = 0;

	virtual fem::Element getElementByIndex(size_t index) const = 0;

	virtual size_t getElementSize() const = 0;
};

using IElementRepositoryPtr = std::shared_ptr<IElementRepository>;

}  // namespace application
}  // namespace gui

#endif	// GUI_APPLICATION_IELEMENTREPOSITORY_H
