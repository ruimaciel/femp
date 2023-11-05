#ifndef FEMP_PERSISTENCE_NODEREPOSITORY_HPP
#define FEMP_PERSISTENCE_NODEREPOSITORY_HPP

// gui includes
#include <application/interfaces/INodeRepository.hpp>
#include <domain/Model.hpp>

// libfemp includes
#include <libfemp/Node.hpp>

// stl includes
#include <memory>

namespace gui {
namespace persistence {

class NodeRepository : public application::INodeRepository {
	public:
	NodeRepository(std::shared_ptr<domain::Model> model);

	// INodeRepository interface
	public:
	std::vector<size_t> getNodeReferenceList() const override;
	std::map<size_t, fem::Node> getNodeMap() const override;
	fem::Node getNodeById(size_t node_id) const override;
	size_t getNodeSize() const override;

	private:
	std::shared_ptr<domain::Model> m_domain_model;
};

}  // namespace persistence
}  // namespace gui

#endif	// FEMP_PERSISTENCE_NODEREPOSITORY_HPP
