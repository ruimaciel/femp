#ifndef NODE_HPP
#define NODE_HPP

#include "point.h++"


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
