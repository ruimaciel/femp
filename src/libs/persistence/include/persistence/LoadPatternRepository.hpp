#ifndef FEMP_PERSISTENCE_LOADPATTERNREPOSITORY_HPP
#define FEMP_PERSISTENCE_LOADPATTERNREPOSITORY_HPP

// gui includes
#include <application/interfaces/ILoadPatternRepository.hpp>
#include <domain/Model.hpp>

// libfemp includes
#include <libfemp/LoadPattern.hpp>

// stl includes
#include <memory>

namespace femp::persistence {

class LoadPatternRepository : public femp::application::ILoadPatternRepository {
public:
  LoadPatternRepository(std::shared_ptr<femp::domain::Model> model);

  // ILoadPatternRepository interface
public:
  std::vector<fem::LoadPattern> getLoadPatternList() const override;

  size_t getLoadPatternSize() const override;

  fem::LoadPattern getLoadPatternByIndex(size_t index) const;

private:
  std::shared_ptr<femp::domain::Model> m_domain_model;
};

} // namespace femp::persistence

#endif // FEMP_PERSISTENCE_LOADPATTERNREPOSITORY_HPP
