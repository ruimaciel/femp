#ifndef GUI_PERSISTENCE_LOADPATTERNREPOSITORY_H
#define GUI_PERSISTENCE_LOADPATTERNREPOSITORY_H

#include <application/interfaces/ILoadPatternRepository.h++>
#include <domain/Model.h++>

namespace gui {
namespace persistence {

class LoadPatternRepository : public application::ILoadPatternRepository {
   public:
	LoadPatternRepository(std::shared_ptr<gui::Model> model);

	// ILoadPatternRepository interface
   public:
	std::vector<fem::LoadPattern> getLoadPatternList() const override;

	size_t getLoadPatternSize() const override;

	fem::LoadPattern getLoadPatternByIndex(size_t index) const;

   private:
	std::shared_ptr<gui::Model> m_domain_model;
};

}  // namespace persistence
}  // namespace gui

#endif	// GUI_PERSISTENCE_LOADPATTERNREPOSITORY_H
