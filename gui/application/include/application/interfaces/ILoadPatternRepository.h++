#ifndef GUI_APPLICATION_ILOADPATTERNREPOSITORY_H
#define GUI_APPLICATION_ILOADPATTERNREPOSITORY_H

#include <vector>

#include <libfemp/LoadPattern.h++>

namespace gui {
namespace application {

class ILoadPatternRepository
{
public:
    ILoadPatternRepository();
    virtual ~ILoadPatternRepository() = default;

    virtual std::vector<fem::LoadPattern> getLoadPatternList() const = 0;
};

} // namespace application
} // namespace gui

#endif // GUI_APPLICATION_ILOADPATTERNREPOSITORY_H
