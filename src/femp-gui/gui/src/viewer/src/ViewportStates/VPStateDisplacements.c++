#include "VPStateDisplacements.h++"

#include <GL/gl.h>
#include <GL/glu.h>	 // for gluQuadric()
#include <assert.h>

#include <algorithm>
#include <application/interfaces/IElementRepository.h++>
#include <application/interfaces/INodeRepository.h++>
#include <libfemp/Model.h++>
#include <libfemp/Surface.h++>
#include <list>
#include <map>
#include <persistence/ElementRepository.h++>
#include <persistence/NodeRepository.h++>
#include <viewer/BaseViewport.h++>

#include "../SceneGraph.h++"
#include "../SceneGraphComponents/SGCNode.h++"
#include "../SceneGraphComponents/SGCNodeRestrictions.h++"
#include "ui/dialogs/DialogScale.h++"
#include "ui/dialogs/SurfaceSubdivisionDialog.h++"

VPStateDisplacements::VPStateDisplacements() : ViewportState() {
	this->m_factory.setElementRepresentationPolicy(m_element_representation_factory.opaque());
	this->m_factory.setDisplacementsPolicy(&m_displacements);
}

VPStateDisplacements::~VPStateDisplacements() {}

void VPStateDisplacements::initialize(BaseViewport* viewport) {
	// build the displaced_nodes from the analysis
	assert(viewport != nullptr);

	this->setDisplacementsScale(1.0);  // TODO tweak this value
	this->m_displacements.setModel(viewport->getProject().getModel());
}

void VPStateDisplacements::populateScenegraph(BaseViewport* viewport) {
	assert(viewport != nullptr);

	scenegraph.clear();

	std::shared_ptr<gui::application::INodeRepository> m_node_repository = std::make_shared<gui::persistence::NodeRepository>(viewport->getDomainModel());

	// add the nodes to the scenegraph
	for (std::pair<std::size_t, fem::Node> node : m_node_repository->getNodeMap()) {
		std::shared_ptr<SceneGraphComponent> component = std::shared_ptr<SceneGraphComponent>(new SGC::Node(node.first, node.second, &this->m_displacements));
		if (component) this->scenegraph.addPrimitiveComponent(SceneGraph::RG_NODES, component);
	}

	fem::Model& femp_model = viewport->getProject().getModel();
	for (std::pair<const fem::node_restriction_ref_t, fem::NodeRestrictions> node_restrictions_pair : femp_model.getNodeRestrictions()) {
		this->scenegraph.addPrimitiveComponent(SceneGraph::RG_NODE_RESTRICTIONS, std::shared_ptr<SceneGraphComponent>(new SGC::NodeRestrictions(
																					 node_restrictions_pair.first, node_restrictions_pair.first,
																					 node_restrictions_pair.second, &this->m_displacements)));
	}

	// add the elements to the scenegraph
	std::shared_ptr<gui::application::IElementRepository> m_element_repository =
		std::make_shared<gui::persistence::ElementRepository>(viewport->getProject().getDomainModel());
	std::vector<fem::Element> element_list = m_element_repository->getElementList();
	for (std::vector<fem::Element>::size_type n = 0; n < m_element_repository->getElementSize(); n++) {
		SGC::Element* element = this->m_factory(n, element_list[n]);
		std::shared_ptr<SceneGraphComponent> component = std::shared_ptr<SceneGraphComponent>(element);
		if (component) this->scenegraph.addPrimitiveComponent(SceneGraph::RG_SURFACES, component);
	}

	// generate the scene graph
	this->scenegraph.generateSceneGraph();
}

void VPStateDisplacements::setAnalysisResult(fem::AnalysisResult& new_result) {
	this->m_displacements.setAnalysisResult(new_result);
}

void VPStateDisplacements::setDisplacementsScale(float new_scale) {
	this->m_displacements.setDisplacementsScale(new_scale);
}

void VPStateDisplacements::setSelection(Selection) {}

void VPStateDisplacements::keyPressEvent(BaseViewport* viewport, QKeyEvent* event) {
	switch (event->key()) {
		case Qt::Key_S:	 // change the displacements scale
		{
			DialogScale ds(1.0f, viewport);
			switch (ds.exec()) {
				case QDialog::Accepted:
					this->setDisplacementsScale(ds.getScale());

					// update the scene
					viewport->update();
					break;

				default:
					break;
			}
		} break;

		case Qt::Key_D:	 // change the displacements scale
		{
			SurfaceSubdivisionDialog ds(2);
			switch (ds.exec()) {
				case QDialog::Accepted:
					m_element_representation_factory.setSurfaceSubdivisionLevel(ds.scale());

					// update the scene
					viewport->update();
					break;

				default:
					break;
			}
		} break;

		case Qt::Key_W:
			m_element_representation_factory.toggleTriangleWireframeRendering();
			viewport->update();
			break;

		default:
			event->ignore();
			break;
	}
}

void VPStateDisplacements::setTrianglesVisible(bool const state) {
	m_element_representation_factory.setTriangleWireframeRendering(state);
}
