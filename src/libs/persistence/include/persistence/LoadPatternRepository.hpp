#ifndef GUI_PERSISTENCE_LOADPATTERNREPOSITORY_H
#define GUI_PERSISTENCE_LOADPATTERNREPOSITORY_H

// gui includes
#include <application/interfaces/ILoadPatternRepository.hpp>
#include <domain/Model.hpp>

// libfemp includes
#include <libfemp/LoadPattern.hpp>

// stl includes
#include <memory>

namespace gui {
namespace persistence {

class LoadPatternRepository : public application::ILoadPatternRepository {
	public:
	LoadPatternRepository(std::shared_ptr<domain::Model> model);

	// ILoadPatternRepository interface
	public:
	std::vector<fem::LoadPattern> getLoadPatternList() const override;

	size_t getLoadPatternSize() const override;

	fem::LoadPattern getLoadPatternByIndex(size_t index) const;

	private:
	std::shared_ptr<domain::Model> m_domain_model;
};

}  // namespace persistence
}  // namespace gui

#endif	// GUI_PERSISTENCE_LOADPATTERNREPOSITORY_H
