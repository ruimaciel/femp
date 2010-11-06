#include "ViewportColors.h++"


ViewportColors::ViewportColors ()
{
	// set helper function
	#define INIT_ELEMENT(ELEMENT, R, G, B) \
	ELEMENT[0] = R, ELEMENT[1] = G, ELEMENT[2] = B;

	INIT_ELEMENT(background, 0.52,0.52,0.68);

	INIT_ELEMENT(node, 0,0.5,0);
	INIT_ELEMENT(selected, 1,0,0);
	INIT_ELEMENT(wireframe,0,0,0);
	INIT_ELEMENT(surface,0,0.5,0);

	INIT_ELEMENT(tetrahedron4, 0, 0.5, 0);
	INIT_ELEMENT(tetrahedron10, 0, 0.5, 0);
	INIT_ELEMENT(hexahedron8, 0, 0.5, 0);
	INIT_ELEMENT(hexahedron20, 0, 0.5, 0);
	INIT_ELEMENT(hexahedron27, 0, 0.5, 0);
	INIT_ELEMENT(prism6, 0, 0.5, 0);

	INIT_ELEMENT(arrow, 1, 0, 0);

	#undef INIT_ELEMENT
}


ViewportColors::~ViewportColors ()
{
}


