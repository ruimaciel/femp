#include "ToggleRenderOperation.h++"

namespace Operation {

ToggleRenderOperation::ToggleRenderOperation(Selection selection, bool state)
{
    this->setSelection(selection);
    this->setRenderState(state);
}

void ToggleRenderOperation::visit(SceneGraphComponent&)
{
}

void ToggleRenderOperation::visit(SGC::Node& node)
{
    auto selected_nodes = m_selection.getNodeReferences();

    node.render = selected_nodes.find(node.reference()) != selected_nodes.end();
}

void ToggleRenderOperation::visit(SGC::Element& element)
{
    auto selected_elements = m_selection.getElementReferences();

    element.render = selected_elements.find(element.reference()) != selected_elements.end();
}
}
