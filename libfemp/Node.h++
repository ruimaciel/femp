#ifndef FEMP_NODE_HPP
#define FEMP_NODE_HPP

#include <libfemp/point.h++>


namespace fem
{

typedef size_t node_ref_t;


class Node: public point 
{
public:
	Node();
	Node(const Node &);
	Node(const point &);
	~Node();
};

}
#endif
