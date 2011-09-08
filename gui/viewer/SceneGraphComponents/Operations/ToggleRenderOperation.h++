#ifndef TOGGLE_RENDER_OPERATION_HPP
#define TOGGLE_RENDER_OPERATION_HPP


#include "OperationsVisitor.h++"

#include "../SceneGraphComponent.h++"
#include "../SGCNode.h++"
#include "../SGCElement.h++"

#include "../../../Selection.h++"


/**
Sets each scene graph component to be rendered or not, according to some criteria
**/
class ToggleRenderOperation
	: public OperationsVisitor
{
protected:
	bool m_render_state;
	Selection	m_selection;

protected:
	void setRenderState(bool &new_state) {m_render_state = new_state; }
	void setSelection(Selection &selection)	{ this->m_selection = selection; }

public:
	/**
	Sets this operation to set each object in the selection with the render flag state
	@param	selection	a set of model objects
	@param	state	rendering state
	**/
	ToggleRenderOperation(Selection selection, bool state);

	// Visitor pattern operations
	void visit(SceneGraphComponent &element) {}
	void visit(SGC::Node &element);
	void visit(SGC::Element &element);
};

#endif
