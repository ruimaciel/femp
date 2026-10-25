#ifndef FEMP_APPLICATION_IMATERIALREPOSITORY_HPP
#define FEMP_APPLICATION_IMATERIALREPOSITORY_HPP

#include <libfemp/Material.hpp>
#include <memory>
#include <vector>

namespace femp::application {

class IMaterialRepository {
public:
  IMaterialRepository();

  virtual ~IMaterialRepository() = default;

  virtual std::vector<fem::Material> getMaterialList() const = 0;

  virtual void pushMaterial(fem::Material) = 0;
};

using IMaterialRepositoryPtr = std::shared_ptr<IMaterialRepository>;

} // namespace femp::application

#endif // FEMP_APPLICATION_IMATERIALREPOSITORY_HPP
