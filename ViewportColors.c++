#include "ViewportColors.h++"


ViewportColors::ViewportColors ()
{
	// set helper function
	#define INIT_ELEMENT(ELEMENT) \
	ELEMENT[0] = 0.5, ELEMENT[1] = 0.5, ELEMENT[2] = 0.5;

	INIT_ELEMENT(node);
	INIT_ELEMENT(wireframe);

	INIT_ELEMENT(tetrahedron4);
	INIT_ELEMENT(tetrahedron10);
	INIT_ELEMENT(hexahedron8);
	INIT_ELEMENT(hexahedron27);

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

	#undef SET_COLOR
}


ViewportColors::~ViewportColors ()
{
}


