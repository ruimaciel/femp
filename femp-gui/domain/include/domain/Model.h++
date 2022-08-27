#ifndef GUI_MODEL_H
#define GUI_MODEL_H

#include <libfemp/Model.h++>
#include <libfemp/NodeRestrictions.h++>
#include <memory>

namespace gui {

class ModelImpl;

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

}  // namespace gui

#endif	// GUI_MODEL_H
