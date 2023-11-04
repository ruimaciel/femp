#include "SceneGraphComponent.hpp"

#include <assert.h>

SceneGraphComponent::SceneGraphComponent() {
	selected = false;
	render = true;
}

SceneGraphComponent::~SceneGraphComponent() {
	// TODO implement a better cleanup code
}

void SceneGraphComponent::paintGL(ViewportData& data, ViewportColors& colors) {
	for (std::shared_ptr<SceneGraphComponent>& component : children) {
		if (component->render) {
			component->paintGL(data, colors);
		}
	}
}

void SceneGraphComponent::pushComponent(std::shared_ptr<SceneGraphComponent> new_component) {
	this->children.push_back(new_component);
}

void SceneGraphComponent::accept(Operation::OperationsVisitor& visitor) {
	for (std::shared_ptr<SceneGraphComponent>& component : children) {
		component->accept(visitor);
	}
}
