#include <persistence/LoadPatternRepository.hpp>

namespace femp::persistence {

LoadPatternRepository::LoadPatternRepository(
    std::shared_ptr<femp::domain::Model> model)
    : m_domain_model(model) {}

std::vector<fem::LoadPattern>
LoadPatternRepository::getLoadPatternList() const {
  return m_domain_model->getLoadPatternList();
}

size_t LoadPatternRepository::getLoadPatternSize() const {
  return m_domain_model->getLoadPatternList().size();
}

fem::LoadPattern
LoadPatternRepository::getLoadPatternByIndex(size_t index) const {
  return m_domain_model->getLoadPatternList()[index];
}

} // namespace femp::persistence
