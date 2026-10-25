#include <persistence/MaterialRepository.hpp>

namespace femp::persistence {

MaterialRepository::MaterialRepository(std::shared_ptr<femp::domain::Model> model)
    : m_domain_model(model) {}

std::vector<fem::Material> MaterialRepository::getMaterialList() const {
  return m_domain_model->getMaterialList();
}

void MaterialRepository::pushMaterial(fem::Material new_material) {
  m_domain_model->pushMaterial(new_material);
}

} // namespace femp::persistence
