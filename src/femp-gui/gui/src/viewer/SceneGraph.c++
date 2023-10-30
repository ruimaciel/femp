#include "SceneGraph.h++"

#include <assert.h>

#include "ModelViewport.h++"
#include "SceneGraphComponents/SceneGraphComponent.h++"

SceneGraph::SceneGraph() {}

SceneGraph::~SceneGraph() {
	this->clear();
}

void SceneGraph::clear() {
	using namespace std;
	// TODO finish this

	// frees the primitives included in the list
	m_primitive_components.clear();

	this->rendering_groups.clear();
}

void SceneGraph::paint(ViewportData& viewport_data, ViewportColors colors) {
	using namespace std;

	for (std::pair<SceneGraph::Groups, RenderGroup> i : rendering_groups) {
		RenderGroup& render_group = i.second;
		if (render_group.isVisible()) {
			render_group.paintGL(viewport_data, colors);
		}
	}

	// render HUD objects
	m_selection.paintGL(viewport_data, colors);
}

void SceneGraph::addPrimitiveComponent(enum Groups group, std::shared_ptr<SceneGraphComponent> new_component) {
	this->m_primitive_components.push_back(new_component);
	this->rendering_groups[group].primitive_components.push_back(new_component);
}

void SceneGraph::generateSceneGraph() {
	for (std::pair<enum SceneGraph::Groups, RenderGroup> e : this->rendering_groups) {
		e.second.generateSceneGraph();
	}
}

void SceneGraph::runOperation(Operation::OperationsVisitor& visitor) {
	for (std::shared_ptr<SceneGraphComponent>& component : this->m_primitive_components) {
		component->accept(visitor);
	}
}

void SceneGraph::setSelectionStart(const fem::Point3D& p) {
	m_selection.setStart(p);
}

void SceneGraph::setSelectionEnd(const fem::Point3D& p) {
	m_selection.setEnd(p);
}

void SceneGraph::setSelectionOff() {
	m_selection.off();
}
