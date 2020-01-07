#include "SceneGraphComponent.h++"

#include <assert.h>

SceneGraphComponent::SceneGraphComponent()
{
    selected = false;
    render = true;
}

SceneGraphComponent::~SceneGraphComponent()
{
    //TODO implement a better cleanup code
}

void SceneGraphComponent::paintGL(ViewportData& data, ViewportColors& colors)
{
    for (std::list<std::shared_ptr<SceneGraphComponent>>::iterator i = this->children.begin(); i != this->children.end(); i++) {
        if ((*i)->render) {
            (*i)->paintGL(data, colors);
        }
    }
}

void SceneGraphComponent::pushComponent(std::shared_ptr<SceneGraphComponent> new_component)
{
    this->children.push_back(new_component);
}

void SceneGraphComponent::accept(Operation::OperationsVisitor& visitor)
{
    for (auto component : children) {
        component->accept(visitor);
    }
}
