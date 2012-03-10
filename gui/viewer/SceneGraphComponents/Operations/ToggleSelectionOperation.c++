#include "ToggleSelectionOperation.h++"

#include <iostream>

ToggleSelectionOperation::ToggleSelectionOperation(Selection selection, bool state)
{
	this->setSelection(selection);
	this->setSelectionState(state);
}


void 
ToggleSelectionOperation::visit(SceneGraphComponent &) 
{
}


void 
ToggleSelectionOperation::visit(SGC::Node &node)
{
	if( m_selection.m_nodes_selected.find(node.reference()) != m_selection.m_nodes_selected.end())
		node.selected = m_selection_state;
	else
		node.selected = !m_selection_state;
}


void 
ToggleSelectionOperation::visit(SGC::Element &element)
{
	if( m_selection.m_elements_selected.find(element.reference()) != m_selection.m_elements_selected.end())
		element.selected = m_selection_state;
	else
		element.selected = !m_selection_state;
}


