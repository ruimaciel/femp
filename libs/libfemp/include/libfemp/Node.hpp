#ifndef FEMP_NODE_HPP
#define FEMP_NODE_HPP

// libfemp includes
#include <libfemp/Point3D.hpp>

namespace fem {

using node_ref_t = size_t;

/**
 * Data type representing a finite element node
 */
class Node : public Point3D {
	public:
	Node();
	Node(const Node&);
	Node(const Point3D&);
	virtual ~Node();
};
}  // namespace fem
#endif
