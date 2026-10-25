#ifndef FEMP_PERSISTENCE_MATERIALREPOSITORY_HPP
#define FEMP_PERSISTENCE_MATERIALREPOSITORY_HPP

// gui includes
#include <application/interfaces/IMaterialRepository.hpp>
#include <domain/Model.hpp>

// libfemp includes
#include <libfemp/Material.hpp>

// stl includes
#include <memory>

namespace femp::persistence {

class MaterialRepository : public femp::application::IMaterialRepository {
public:
  MaterialRepository(std::shared_ptr<femp::domain::Model> model);

  // IMaterialRepository interface
public:
  std::vector<fem::Material> getMaterialList() const override;

  void pushMaterial(fem::Material new_material) override;

private:
  std::shared_ptr<femp::domain::Model> m_domain_model;
};

} // namespace femp::persistence

#endif // FEMP_PERSISTENCE_MATERIALREPOSITORY_HPP
