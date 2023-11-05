#ifndef FEMP_VIEWER_SGC_PICKRAY_HPP
#define FEMP_VIEWER_SGC_PICKRAY_HPP

#include <libfemp/NodeRestrictions.hpp>
#include <libfemp/Point3D.hpp>
#include <options/Options.hpp>
#include <viewer/ViewportData.hpp>

#include "Operations/OperationsVisitor.hpp"
#include "SceneGraphComponent.hpp"

namespace SGC {

/**
 * Scene graph component used to debug picking operation
 */
class PickRay : public SceneGraphComponent {
	protected:
	fem::Point3D m_origin, m_destination;
	float radius;

	public:
	PickRay(fem::Point3D const& origin, fem::Point3D const& destination, float const& radius);
	~PickRay();

	/**
	 * Renders this node
	 */
	void paintGL(ViewportData& data, ViewportColors& colors);

	/**
	 * Visitor pattern method
	 */
	void accept(Operation::OperationsVisitor& visitor);
};

}  // namespace SGC

#endif
