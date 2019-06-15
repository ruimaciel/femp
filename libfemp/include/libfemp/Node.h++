#ifndef FEMP_NODE_HPP
#define FEMP_NODE_HPP

#include <libfemp/Point3D.h++>

namespace fem {

using node_ref_t = size_t;

/**
 * Data type representing a finite element node
 **/
class Node
    : public Point3D {
public:
    Node();
    Node(const Node&);
    Node(const Point3D&);
    virtual ~Node();
};

}
#endif
