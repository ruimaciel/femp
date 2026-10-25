#ifndef FEMP_SERVICES_ISELECTIONSERVICE_HPP
#define FEMP_SERVICES_ISELECTIONSERVICE_HPP

#include <cstddef>
#include <set>

#include "Selection.hpp"

namespace femp::services {

class ISelectionService {
public:
  ISelectionService();
  virtual ~ISelectionService() = default;

  virtual Selection getSelection() const = 0;
  virtual std::set<std::size_t> getSelectedElementReferences() const = 0;
  virtual std::set<std::size_t> getSelectedNodeReferences() const = 0;
};

} // namespace femp::services

#endif // FEMP_SERVICES_ISELECTIONSERVICE_HPP
