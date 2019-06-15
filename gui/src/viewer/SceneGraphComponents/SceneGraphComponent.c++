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
    for (std::list<SceneGraphComponent*>::iterator i = this->children.begin(); i != this->children.end(); i++) {
        if ((*i)->render) {
            (*i)->paintGL(data, colors);
        }
    }
}

void SceneGraphComponent::pushComponent(SceneGraphComponent* new_component)
{
    assert(new_component != nullptr);

    this->children.push_back(new_component);
}

void SceneGraphComponent::accept(Operation::OperationsVisitor& visitor)
{
    for (std::list<SceneGraphComponent*>::iterator i = this->children.begin(); i != this->children.end(); i++) {
        (*i)->accept(visitor);
    }
}
