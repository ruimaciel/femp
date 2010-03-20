#ifndef NODE_HPP
#define NODE_HPP

#include "point.h++"


namespace fem
{

class Node: public point 
{
	public:
		Node();
		Node(const Node &);
		~Node();
};

}
#endif
