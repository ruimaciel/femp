#ifndef FEMP_NODE_HPP
#define FEMP_NODE_HPP

#include <libfemp/Point.h++>


namespace fem
{

typedef size_t node_ref_t;


/**
 * Data type representing a finite element node
 **/
class Node
	: public Point 
{
public:
	Node();
	Node(const Node &);
	Node(const Point &);
	~Node();
};

}
#endif
