#include <assert.h>

#include <iostream>
#include <libfemp/Element.hpp>

namespace fem {

Element::~Element() {}

material_ref_t Element::getMaterialRef() const {
	return material;
}

size_t Element::getNodeAmount() const {
	switch (this->type) {
		case FE_TRIANGLE3:
			return 3;
			break;

		case FE_TRIANGLE6:
			return 6;
			break;

		case FE_TRIANGLE10:
			return 10;
			break;

		case FE_QUADRANGLE4:
			return 4;
			break;

		case FE_QUADRANGLE8:
			return 8;
			break;

		case FE_QUADRANGLE9:
			return 9;
			break;

		case FE_TETRAHEDRON4:
			return 4;
			break;

		case FE_TETRAHEDRON10:
			return 10;
			break;

		case FE_HEXAHEDRON8:
			return 8;
			break;

		case FE_HEXAHEDRON20:
			return 20;
			break;

		case FE_HEXAHEDRON27:
			return 27;
			break;

		case FE_PRISM6:
			return 6;
			break;

		case FE_PRISM15:
			return 15;
			break;

		case FE_PRISM18:
			return 18;
			break;

		default:
			std::cerr << "Element::getNodeAmount(): unsupported element: type " << this->type << std::endl;
			assert(0);
			break;
	}
}

enum Element::ElementFamily Element::family() const {
	switch (this->type) {
		case FE_TRIANGLE3:
		case FE_TRIANGLE6:
		case FE_TRIANGLE10:
		case FE_TRIANGLE15:
		case FE_TRIANGLE21:
		case FE_ITRIANGLE9:
		case FE_ITRIANGLE12:
		case FE_ITRIANGLE15:
			return EF_TRIANGLE;
			break;

		case FE_QUADRANGLE4:
		case FE_QUADRANGLE8:
		case FE_QUADRANGLE9:
			return EF_QUADRILATERAL;
			break;

		case FE_TETRAHEDRON4:
		case FE_TETRAHEDRON10:
		case FE_TETRAHEDRON20:
		case FE_TETRAHEDRON35:
		case FE_TETRAHEDRON56:
			return EF_TETRAHEDRON;
			break;

		case FE_HEXAHEDRON8:
		case FE_HEXAHEDRON20:
		case FE_HEXAHEDRON27:
			return EF_HEXAHEDRON;
			break;

		case FE_PRISM6:
		case FE_PRISM18:
		case FE_PRISM15:
			return EF_PRISM;
			break;

		case FE_PYRAMID5:
		case FE_PYRAMID14:
		case FE_PYRAMID13:
			return EF_PYRAMID;
			break;

		default:
			return EF_INVALID;
			break;
	}
}

Element::Type Element::getType() const {
	return type;
}

std::vector<size_t> Element::getNodeReferences() const {
	return this->nodes;
}

node_ref_t Element::getNode(node_ref_t ref) const {
	return this->nodes[ref];
}

void Element::clear() {}

}  // namespace fem
