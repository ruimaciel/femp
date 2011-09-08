#include "ToggleRenderOperation.h++"


ToggleRenderOperation::ToggleRenderOperation(Selection selection, bool state)
{
	this->setSelection(selection);
	this->setRenderState(state);
}


void 
ToggleRenderOperation::visit(SGC::Node &element)
{
	element.render = m_render_state;
}


void 
ToggleRenderOperation::visit(SGC::Element &element)
{
	element.render = m_render_state;
}


