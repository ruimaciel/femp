#ifndef GUI_MODELIMPL_H
#define GUI_MODELIMPL_H

#include <libfemp/Model.h++>
#include <libfemp/NodeRestrictions.h++>

namespace gui {

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

}  // namespace gui

#endif	// GUI_MODELIMPL_H
