#ifndef SELECT_RAY_INTERSECTION_OPERATION_HPP
#define SELECT_RAY_INTERSECTION_OPERATION_HPP

#include <libfemp/Point3D.hpp>
#include <selection/Selection.hpp>

#include "../SGCElement.hpp"
#include "../SGCNode.hpp"
#include "../SceneGraphComponent.hpp"
#include "OperationsVisitor.hpp"

namespace Operation {

/**
Sets each scene graph component to be rendered or not, according to some
criteria
**/
class SelectRayIntersectionOperation : public OperationsVisitor {
	protected:
	fem::Point3D m_origin;		 // ray origin point
	fem::Point3D m_destination;	 // ray destination point

	Selection* m_selection;	 // pointer to selection object, where all the
							 // selected objects will be set

	float A, B, C;	// for the quadratic equation in the ray-sphere intersection
	float r;		// intersection radius

	public:
	/**
		Sets this operation to set each object in the selection with the render
	   flag state
		@param	selection	a set of model objects
		@param	state	rendering state
		**/
	SelectRayIntersectionOperation(Selection& selection, fem::Point3D const& origin, fem::Point3D const& destination, float const& radius);

	// Visitor pattern operations
	void visit(SceneGraphComponent&);
	void visit(SGC::Node& element);
	void visit(SGC::Element& element);
};
}  // namespace Operation

#endif