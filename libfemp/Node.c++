#include "Node.h++"

namespace fem
{


Node::Node()
{
}


Node::Node(const Node &copied)
	: Point(copied)
{
}


Node::Node(const Point &copied)
	: Point(copied)
{
}


Node::~Node()
{
}


}	// namespace fem

