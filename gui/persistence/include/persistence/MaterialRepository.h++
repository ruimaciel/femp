#ifndef GUI_PERSISTENCE_MATERIALREPOSITORY_H
#define GUI_PERSISTENCE_MATERIALREPOSITORY_H

#include <Model.h++>
#include <memory>

#include <application/interfaces/IMaterialRepository.h++>



namespace gui {
namespace persistence {

class MaterialRepository : public application::IMaterialRepository
{
public:
    MaterialRepository(std::shared_ptr<gui::Model> model);

    // IMaterialRepository interface
public:
    std::vector<fem::Material> getMaterialList() const override;

    void pushMaterial(fem::Material new_material) override;

private:
    std::shared_ptr<gui::Model> m_domain_model;
};

} // namespace persistence
} // namespace gui

#endif // GUI_PERSISTENCE_MATERIALREPOSITORY_H
