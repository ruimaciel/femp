#ifndef VIEWPORT_COLORS_HPP
#define VIEWPORT_COLORS_HPP

#include <GL/gl.h>

struct ViewportColors {
	ViewportColors ();
	ViewportColors (const ViewportColors &);
	~ViewportColors ();

	// set of color options
	GLfloat tetrahedron8[3];
};


#endif
