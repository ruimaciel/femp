#include <persistence/MaterialRepository.h++>

namespace gui {
namespace persistence {

MaterialRepository::MaterialRepository(std::shared_ptr<gui::Model> model)
    : m_domain_model(model)
{

}

std::vector<fem::Material> MaterialRepository::getMaterialList() const
{
    return m_domain_model->getMaterialList();
}

} // namespace persistence
} // namespace gui
