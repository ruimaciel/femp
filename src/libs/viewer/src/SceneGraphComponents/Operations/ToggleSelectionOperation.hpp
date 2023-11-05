#ifndef FEMP_VIEWER_TOGGLESELECTIONOPERATION_HPP
#define FEMP_VIEWER_TOGGLESELECTIONOPERATION_HPP

#include <selection/Selection.hpp>

#include "../SGCElement.hpp"
#include "../SGCNode.hpp"
#include "../SceneGraphComponent.hpp"
#include "OperationsVisitor.hpp"

namespace Operation {

/**
Sets each scene graph component to be rendered as selected
**/
class ToggleSelectionOperation : public OperationsVisitor {
	protected:
	bool m_selection_state;
	Selection m_selection;

	protected:
	void setSelectionState(bool& new_state) {
		m_selection_state = new_state;
	}
	void setSelection(Selection& selection) {
		this->m_selection = selection;
	}

	public:
	/**
		Sets this operation to set each object in the selection with the render
	   flag state
		@param	selection	a set of model objects
		@param	state	rendering state
		**/
	ToggleSelectionOperation(Selection selection, bool state = true);

	// Visitor pattern operations
	void visit(SceneGraphComponent&);
	void visit(SGC::Node& element);
	void visit(SGC::Element& element);
};
}  // namespace Operation

#endif
