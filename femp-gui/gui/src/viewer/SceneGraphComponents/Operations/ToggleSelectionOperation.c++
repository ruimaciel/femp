#include "ToggleSelectionOperation.h++"

namespace Operation {

ToggleSelectionOperation::ToggleSelectionOperation(Selection selection, bool state)
{
    this->setSelection(selection);
    this->setSelectionState(state);
}

void ToggleSelectionOperation::visit(SceneGraphComponent&)
{
}

void ToggleSelectionOperation::visit(SGC::Node& node)
{
    auto selected_nodes = m_selection.getNodeReferences();
    if (selected_nodes.find(node.reference()) != selected_nodes.end())
        node.selected = m_selection_state;
    else
        node.selected = !m_selection_state;
}

void ToggleSelectionOperation::visit(SGC::Element& element)
{
    auto selected_elements = m_selection.getElementReferences();
    if (selected_elements.find(element.reference()) != selected_elements.end())
        element.selected = m_selection_state;
    else
        element.selected = !m_selection_state;
}

}
