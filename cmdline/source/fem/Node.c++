#include "Node.h++"

namespace fem
{


Node::Node()
{
}


Node::Node(const Node &copied)
	: point(copied)
{
}


Node::Node(const point &copied)
	: point(copied)
{
}


Node::~Node()
{
}


}

