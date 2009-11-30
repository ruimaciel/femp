#include "ViewportColors.h++"


ViewportColors::ViewportColors ()
{
	// set helper function
	#define INIT_ELEMENT(ELEMENT) \
	ELEMENT[0] = 0, ELEMENT[1] = 0, ELEMENT[2] = 0;

	INIT_ELEMENT(node);
	INIT_ELEMENT(tetrahedron4);
	INIT_ELEMENT(hexahedron8);

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
	SET_COLOR(tetrahedron4);
	SET_COLOR(hexahedron8);

	#undef SET_COLOR
}


ViewportColors::~ViewportColors ()
{
}


