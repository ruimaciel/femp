#include "ToggleRenderOperation.h++"

#include <iostream>

ToggleRenderOperation::ToggleRenderOperation(Selection selection, bool state)
{
	this->setSelection(selection);
	this->setRenderState(state);
}


void 
ToggleRenderOperation::visit(SceneGraphComponent &) 
{
	std::cout << "ToggleRenderOperation::visit(SceneGraphComponent &)" << std::endl;
}


void 
ToggleRenderOperation::visit(SGC::Node &node)
{
	std::cout << "ToggleRenderOperation::visit(SGC::Node &node)" << std::endl;
	if( m_selection.m_nodes_selected.find(node.reference()) != m_selection.m_nodes_selected.end())
		node.render = m_render_state;
	else
		node.render = !m_render_state;
}


void 
ToggleRenderOperation::visit(SGC::Element &element)
{
	std::cout << "ToggleRenderOperation::visit(SGC::Element &element)" << std::endl;
	// if element is selected
	if( m_selection.m_elements_selected.find(element.reference()) != m_selection.m_elements_selected.end())
		element.render = m_render_state;
	else
		element.render = !m_render_state;
}


