#include "ViewportColors.h++"


ViewportColors::ViewportColors ()
{
	// set helper function
	#define INIT_ELEMENT(ELEMENT, R, G, B) \
	ELEMENT[0] = R, ELEMENT[1] = G, ELEMENT[2] = B;

	INIT_ELEMENT(node, 0,0.5,0);
	INIT_ELEMENT(wireframe,0,0,0);

	INIT_ELEMENT(tetrahedron4, 0, 0.5, 0);
	INIT_ELEMENT(tetrahedron10, 0, 0.5, 0);
	INIT_ELEMENT(hexahedron8, 0, 0.5, 0);
	INIT_ELEMENT(hexahedron27, 0, 0.5, 0);
	INIT_ELEMENT(prism6, 0, 0.5, 0);

	INIT_ELEMENT(arrow, 1, 0, 0);

	#undef INIT_ELEMENT
}


ViewportColors::ViewportColors (const ViewportColors &copied)
{
	// define a helper function
	#define SET_COLOR(ELEMENT) { \
	ELEMENT[0] = copied.ELEMENT[0]; \
	ELEMENT[1] = copied.ELEMENT[1]; \
	ELEMENT[2] = copied.ELEMENT[2]; \
	}

	// set the element colors
	SET_COLOR(node);
	SET_COLOR(wireframe);

	SET_COLOR(tetrahedron4);
	SET_COLOR(tetrahedron10);
	SET_COLOR(hexahedron8);
	SET_COLOR(hexahedron27);
	SET_COLOR(prism6);

	SET_COLOR(arrow);

	#undef SET_COLOR
}


ViewportColors::~ViewportColors ()
{
}


