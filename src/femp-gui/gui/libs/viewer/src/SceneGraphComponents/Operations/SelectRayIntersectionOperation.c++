#include "SelectRayIntersectionOperation.h++"

namespace Operation {

SelectRayIntersectionOperation::SelectRayIntersectionOperation(Selection& selection, fem::Point3D const& origin, fem::Point3D const& destination,
															   float const& radius) {
	this->m_selection = &selection;
	m_origin = origin;
	m_destination = destination;
	r = radius;	 // TODO change this to reflect render radius
}

void SelectRayIntersectionOperation::visit(SceneGraphComponent&) {}

void SelectRayIntersectionOperation::visit(SGC::Node& node) {
	fem::Point3D d = (m_destination - m_origin);
	A = dot_product(d, d);
	B = 2 * dot_product(m_origin - node.pos(), d);
	C = dot_product(m_origin - node.pos(), m_origin - node.pos()) - r * r;

	if (B * B - 4 * A * C >= 0) {
		// ray intersects node
		// TODO tweak this so that the closest node is the only node selected
		m_selection->selectNode(node.reference());
	}
}

void SelectRayIntersectionOperation::visit(SGC::Element&) {}
}  // namespace Operation
