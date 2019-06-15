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
    if (selected_nodes.find(node.reference()) != selected_nodes.end())
        node.render = m_render_state;
    else
        node.render = !m_render_state;
}

void ToggleRenderOperation::visit(SGC::Element& element)
{
    auto selected_elements = m_selection.getElementReferences();
    if (selected_elements.find(element.reference()) != selected_elements.end())
        element.render = m_render_state;
    else
        element.render = !m_render_state;
}

}
