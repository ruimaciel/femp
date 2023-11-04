#include <persistence/LoadPatternRepository.hpp>

namespace gui {
namespace persistence {

LoadPatternRepository::LoadPatternRepository(std::shared_ptr<gui::Model> model) : m_domain_model(model) {}

std::vector<fem::LoadPattern> LoadPatternRepository::getLoadPatternList() const {
	return m_domain_model->getLoadPatternList();
}

size_t LoadPatternRepository::getLoadPatternSize() const {
	return m_domain_model->getLoadPatternList().size();
}

fem::LoadPattern LoadPatternRepository::getLoadPatternByIndex(size_t index) const {
	return m_domain_model->getLoadPatternList()[index];
}

}  // namespace persistence
}  // namespace gui
