#ifndef GUI_APPLICATION_IMATERIALREPOSITORY_H
#define GUI_APPLICATION_IMATERIALREPOSITORY_H

#include <vector>

#include <libfemp/Material.h++>


namespace gui {
namespace application {

class IMaterialRepository
{
public:
    IMaterialRepository();

    virtual ~IMaterialRepository() = default;

    virtual std::vector<fem::Material> getMaterialList() const = 0;
};

} // namespace application
} // namespace gui

#endif // GUI_APPLICATION_IMATERIALREPOSITORY_H
