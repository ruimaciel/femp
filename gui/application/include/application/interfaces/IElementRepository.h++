#ifndef GUI_APPLICATION_ELEMENTREPOSITORY_H
#define GUI_APPLICATION_ELEMENTREPOSITORY_H

#include <libfemp/Element.h++>

namespace gui {
namespace application {

class IElementRepository
{
public:
    IElementRepository();

    virtual ~IElementRepository();

    virtual fem::Element getElementById(size_t element_id) const = 0;

    virtual fem::Element getElementByIndex(size_t index) const = 0;

    virtual size_t getElementSize() const = 0;
};


} // namespace persistence
} // namespace gui

#endif // GUI_APPLICATION_ELEMENTREPOSITORY_H
