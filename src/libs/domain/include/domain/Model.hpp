#ifndef FEMP_DOMAIN_MODEL_H
#define FEMP_DOMAIN_MODEL_H

// libfemp includes
#include <libfemp/ElementGroup.hpp>
#include <libfemp/LoadPattern.hpp>
#include <libfemp/Material.hpp>
#include <libfemp/Model.hpp>
#include <libfemp/Node.hpp>
#include <libfemp/NodeGroup.hpp>
#include <libfemp/NodeRestrictions.hpp>

// stl includes
#include <map>
#include <memory>
#include <vector>

class ModelImpl;

namespace domain {
class Model {
	public:
	Model(fem::Model& model);
	~Model();

	std::vector<fem::Element> getElementList() const;
	fem::Element getElementByReference(size_t element_ref) const;
	size_t getElementSize() const;

	std::vector<size_t> getNodeReferenceList() const;
	std::map<size_t, fem::Node> getNodeMap() const;
	fem::Node getNodeByReference(size_t node_reference) const;

	std::vector<fem::NodeGroup> getNodeGroupList() const;

	std::vector<fem::ElementGroup> getElementGroupList() const;

	std::vector<fem::LoadPattern> getLoadPatternList() const;

	std::vector<fem::Material> getMaterialList() const;
	void pushMaterial(fem::Material new_material);

	std::map<unsigned int, fem::NodeRestrictions> getNodeRestrictions() const;

	private:
	std::unique_ptr<ModelImpl> m_impl;
};

}  // namespace domain
#endif	// FEMP_DOMAIN_MODEL_H
