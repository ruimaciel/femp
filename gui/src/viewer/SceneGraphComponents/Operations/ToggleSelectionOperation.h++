#ifndef TOGGLE_SELECTION_OPERATION_HPP
#define TOGGLE_SELECTION_OPERATION_HPP

#include "OperationsVisitor.h++"

#include "../SGCElement.h++"
#include "../SGCNode.h++"
#include "../SceneGraphComponent.h++"

#include <Selection.h++>

namespace Operation {

/**
Sets each scene graph component to be rendered as selected
**/
class ToggleSelectionOperation
    : public OperationsVisitor {
protected:
    bool m_selection_state;
    Selection m_selection;

protected:
    void setSelectionState(bool& new_state) { m_selection_state = new_state; }
    void setSelection(Selection& selection) { this->m_selection = selection; }

public:
    /**
	Sets this operation to set each object in the selection with the render flag state
	@param	selection	a set of model objects
	@param	state	rendering state
	**/
    ToggleSelectionOperation(Selection selection, bool state = true);

    // Visitor pattern operations
    void visit(SceneGraphComponent&);
    void visit(SGC::Node& element);
    void visit(SGC::Element& element);
};

}

#endif
