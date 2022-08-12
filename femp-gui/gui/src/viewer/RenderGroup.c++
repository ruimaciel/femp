#include "RenderGroup.h++"

RenderGroup::RenderGroup() {
	this->m_render = true;

	// display_list = glGenLists(1);
}

void RenderGroup::generateSceneGraph() {
	for (auto i : this->primitive_components) {
		this->scenegraph.pushComponent(i);
	}
}

void RenderGroup::setVisible(bool visible) { this->m_render = visible; }

bool RenderGroup::isVisible() const { return this->m_render; }

void RenderGroup::paintGL(ViewportData& data, ViewportColors& colors) { this->scenegraph.paintGL(data, colors); }
