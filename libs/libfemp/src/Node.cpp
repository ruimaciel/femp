#include <libfemp/Node.hpp>

namespace fem {

Node::Node() {}

Node::Node(const Node& copied) : Point3D(copied) {}

Node::Node(const Point3D& copied) : Point3D(copied) {}

Node::~Node() {}

}  // namespace fem
