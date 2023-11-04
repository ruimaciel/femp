#include <persistence/ElementRepository.hpp>

namespace gui {
namespace persistence {

ElementRepository::ElementRepository(std::shared_ptr<gui::Model> model) : m_domain_model(model) {}

std::vector<fem::Element> ElementRepository::getElementList() const {
	return m_domain_model->getElementList();
}

fem::Element ElementRepository::getElementById(size_t element_id) const {
	return m_domain_model->getElementByReference(element_id);
}

fem::Element ElementRepository::getElementByIndex(size_t index) const {
	return m_domain_model->getElementByReference(index);
}

size_t ElementRepository::getElementSize() const {
	return m_domain_model->getElementSize();
}

}  // namespace persistence
}  // namespace gui
