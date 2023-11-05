#ifndef FEMP_PERSISTENCE_ELEMENTREPOSITORY_HPP
#define FEMP_PERSISTENCE_ELEMENTREPOSITORY_HPP

// femp includes
#include <application/interfaces/IElementRepository.hpp>
#include <domain/Model.hpp>

// libfemp includes
#include <libfemp/Element.hpp>

// stl includes
#include <memory>

namespace gui {
namespace persistence {

class ElementRepository : public application::IElementRepository {
	public:
	ElementRepository(std::shared_ptr<domain::Model> model);

	std::vector<fem::Element> getElementList() const override;
	fem::Element getElementById(size_t element_id) const override;
	fem::Element getElementByIndex(size_t index) const override;
	size_t getElementSize() const override;

	private:
	std::shared_ptr<domain::Model> m_domain_model;
};

}  // namespace persistence
}  // namespace gui

#endif	// FEMP_PERSISTENCE_ELEMENTREPOSITORY_HPP
