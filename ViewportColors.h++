#ifndef VIEWPORT_COLORS_HPP
#define VIEWPORT_COLORS_HPP

#include <GL/gl.h>

struct ViewportColors {
	ViewportColors ();
	ViewportColors (const ViewportColors &);
	~ViewportColors ();

	// set of color options
	GLfloat node[3];
	GLfloat tetrahedron4[3];
	GLfloat hexahedron8[3];
};


#endif
