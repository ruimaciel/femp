#ifndef OPERATIONS_VISITOR_HPP
#define OPERATIONS_VISITOR_HPP


class SceneGraphComponent;
class SGCNode;
class SGCSurface;


/*
Base class for a Visitor pattern which is used to operate on selected scene objects
*/
class OperationsVisitor
{
	public:
		virtual void visit(SceneGraphComponent &element) = 0;
		virtual void visit(SGCNode &element) = 0;
		virtual void visit(SGCSurface &element) = 0;
};



#endif
