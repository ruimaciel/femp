#ifndef OPERATIONS_VISITOR_HPP
#define OPERATIONS_VISITOR_HPP


class SceneGraphComponent;

namespace SGC
{
class Node;
class Element; 
}

/*
Base class for a Visitor pattern which is used to operate on selected scene objects
*/
class OperationsVisitor
{
public:
	virtual void visit(SceneGraphComponent &element) = 0;
	virtual void visit(SGC::Node &element) = 0;
	virtual void visit(SGC::Element &element) = 0;
};



#endif
