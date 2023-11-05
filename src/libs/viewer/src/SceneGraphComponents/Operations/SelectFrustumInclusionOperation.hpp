#ifndef SELECT_FRUSTUM_INCLUSION_OPERATION_HPP
#define SELECT_FRUSTUM_INCLUSION_OPERATION_HPP

#include <array>
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
class SelectFrustumInclusionOperation : public OperationsVisitor {
	protected:
	std::array<fem::Point3D, 4> m_near;	 // near plane vertices
	std::array<fem::Point3D, 4> m_far;	 // far plane vertices

	std::array<fem::Point3D, 4> m_normal;  // normal vector of each side plane, facing inward

	Selection& m_selection;

	public:
	/**
		Sets this operation to set each object in the selection with the render
	   flag state
		@param	selection	a set of model objects
		@param	state	rendering state
		**/
	SelectFrustumInclusionOperation(Selection& selection, std::array<fem::Point3D, 4> const& near, std::array<fem::Point3D, 4> const& far);

	// Visitor pattern operations
	void visit(SceneGraphComponent&);
	void visit(SGC::Node& element);
	void visit(SGC::Element& element);

	void selectInclusiveElements(std::shared_ptr<domain::Model> model);

	protected:
	void calculateNormalVectors(std::array<fem::Point3D, 4> const& near, std::array<fem::Point3D, 4> const& far);
};
}  // namespace Operation

#endif
