#include <persistence/MaterialRepository.hpp>

namespace gui {
namespace persistence {

MaterialRepository::MaterialRepository(std::shared_ptr<gui::Model> model) : m_domain_model(model) {}

std::vector<fem::Material> MaterialRepository::getMaterialList() const {
	return m_domain_model->getMaterialList();
}

void MaterialRepository::pushMaterial(fem::Material new_material) {
	m_domain_model->pushMaterial(new_material);
}

}  // namespace persistence
}  // namespace gui
