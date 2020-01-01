#ifndef GUI_PERSISTENCE_ELEMENTREPOSITORY_H
#define GUI_PERSISTENCE_ELEMENTREPOSITORY_H

#include <libfemp/Element.h++>
#include <application/interfaces/IElementRepository.h++>

namespace gui {
namespace persistence {

class ElementRepository : public application::IElementRepository
{
public:
    ElementRepository();
    virtual ~ElementRepository();

    virtual fem::Element getElementById(size_t element_id) const = 0;

    virtual fem::Element getElementByIndex(size_t index) const = 0;
    virtual size_t getElementSize() const = 0;
};


} // namespace persistence
} // namespace gui

#endif // GUI_PERSISTENCE_ELEMENTREPOSITORY_H
