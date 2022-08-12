#ifndef GUI_PERSISTENCE_ELEMENTREPOSITORY_H
#define GUI_PERSISTENCE_ELEMENTREPOSITORY_H

#include <application/interfaces/IElementRepository.h++>
#include <domain/Model.h++>
#include <libfemp/Element.h++>
#include <memory>

namespace gui {
namespace persistence {

class ElementRepository : public application::IElementRepository {
   public:
	ElementRepository(std::shared_ptr<gui::Model> model);

	std::vector<fem::Element> getElementList() const override;
	fem::Element getElementById(size_t element_id) const override;
	fem::Element getElementByIndex(size_t index) const override;
	size_t getElementSize() const override;

   private:
	std::shared_ptr<gui::Model> m_domain_model;
};

}  // namespace persistence
}  // namespace gui

#endif	// GUI_PERSISTENCE_ELEMENTREPOSITORY_H
