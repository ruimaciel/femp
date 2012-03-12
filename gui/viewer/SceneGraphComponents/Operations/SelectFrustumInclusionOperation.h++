#ifndef SELECT_FRUSTUM_INCLUSION_OPERATION_HPP
#define SELECT_FRUSTUM_INCLUSION_OPERATION_HPP


#include <array>
#include "OperationsVisitor.h++"

#include "../SceneGraphComponent.h++"
#include "../SGCNode.h++"
#include "../SGCElement.h++"

#include "../../../Selection.h++"
#include "../../../fem/point.h++"


namespace Operation
{

/**
Sets each scene graph component to be rendered or not, according to some criteria
**/
class SelectFrustumInclusionOperation
	: public OperationsVisitor
{
protected:
	std::array<fem::point, 4> m_near;		// near plane vertices
	std::array<fem::point, 4> m_far;		// far plane vertices

	std::array<fem::point, 4> m_normal;		// normal vector of each side plane, facing inward

	Selection	*m_selection;	// pointer to selection object, where all the selected objects will be set

public:
	/**
	Sets this operation to set each object in the selection with the render flag state
	@param	selection	a set of model objects
	@param	state	rendering state
	**/
	SelectFrustumInclusionOperation(Selection &selection, std::array<fem::point,4> const &near, std::array<fem::point,4> const &far);

	// Visitor pattern operations
	void visit(SceneGraphComponent &);
	void visit(SGC::Node &element);
	void visit(SGC::Element &element);

	void selectInclusiveElements(fem::Project const &project);

protected:
	void calculateNormalVectors(std::array<fem::point, 4> const &near, std::array<fem::point, 4> const &far);
};

}

#endif
