#ifndef FEMP_DOMAIN_MODELIMPL_HPP
#define FEMP_DOMAIN_MODELIMPL_HPP

#include <libfemp/Model.hpp>
#include <libfemp/NodeRestrictions.hpp>

class ModelImpl {
	public:
	ModelImpl(fem::Model& model);

	std::vector<fem::Element> getElementList() const;
	fem::Element getElementByReference(size_t element_ref) const;

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
	fem::Model& m_model;
};

#endif	// FEMP_DOMAIN_MODELIMPL_HPP
