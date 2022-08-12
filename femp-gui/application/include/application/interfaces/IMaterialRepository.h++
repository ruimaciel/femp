#ifndef GUI_APPLICATION_IMATERIALREPOSITORY_H
#define GUI_APPLICATION_IMATERIALREPOSITORY_H

#include <libfemp/Material.h++>
#include <memory>
#include <vector>

namespace gui {
namespace application {

class IMaterialRepository {
   public:
	IMaterialRepository();

	virtual ~IMaterialRepository() = default;

	virtual std::vector<fem::Material> getMaterialList() const = 0;

	virtual void pushMaterial(fem::Material) = 0;
};

using IMaterialRepositoryPtr = std::shared_ptr<IMaterialRepository>;

}  // namespace application
}  // namespace gui

#endif	// GUI_APPLICATION_IMATERIALREPOSITORY_H
