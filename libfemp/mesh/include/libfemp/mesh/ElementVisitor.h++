#ifndef FEM_MESH_ELEMENTVISITOR_H
#define FEM_MESH_ELEMENTVISITOR_H

namespace fem {
namespace mesh {

// forward declarations
class Hexahedron8;
class Hexahedron20;
class Hexahedron27;
class Prism6;
class Prism15;
class Prism18;
class Tetrahedron4;
class Tetrahedron10;
class Tetrahedron20;
class Tetrahedron35;
class Tetrahedron56;

class ElementVisitor {
	public:
	virtual ~ElementVisitor() = default;

	virtual void visit(Hexahedron8& element) = 0;
	virtual void visit(Hexahedron20& element) = 0;
	virtual void visit(Hexahedron27& element) = 0;
	virtual void visit(Prism6& element) = 0;
	virtual void visit(Prism15& element) = 0;
	virtual void visit(Prism18& element) = 0;
	virtual void visit(Tetrahedron4& element) = 0;
	virtual void visit(Tetrahedron10& element) = 0;
	virtual void visit(Tetrahedron20& element) = 0;
	virtual void visit(Tetrahedron35& element) = 0;
	virtual void visit(Tetrahedron56& element) = 0;
};

}  // namespace mesh
}  // namespace fem

#endif	// FEM_MESH_ELEMENTVISITOR_H
