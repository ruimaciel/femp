#ifndef FEMP_NODE_HPP
#define FEMP_NODE_HPP

#include <libfemp/Point.h++>


namespace fem
{

typedef size_t node_ref_t;


class Node: public Point 
{
public:
	Node();
	Node(const Node &);
	Node(const Point &);
	~Node();
};

}
#endif
