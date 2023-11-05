#ifndef FEMP_APPLICATION_ILOADPATTERNREPOSITORY_H
#define FEMP_APPLICATION_ILOADPATTERNREPOSITORY_H

#include <libfemp/LoadPattern.hpp>
#include <memory>
#include <vector>

namespace gui {
namespace application {

class ILoadPatternRepository {
	public:
	ILoadPatternRepository();
	virtual ~ILoadPatternRepository() = default;

	virtual std::vector<fem::LoadPattern> getLoadPatternList() const = 0;

	virtual size_t getLoadPatternSize() const = 0;

	virtual fem::LoadPattern getLoadPatternByIndex(size_t index) const = 0;
};

using ILoadPatternRepositoryPtr = std::shared_ptr<ILoadPatternRepository>;

}  // namespace application
}  // namespace gui

#endif	// FEMP_APPLICATION_ILOADPATTERNREPOSITORY_H
