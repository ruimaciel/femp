#ifndef VIEWPORT_COLORS_HPP
#define VIEWPORT_COLORS_HPP

#include <GL/gl.h>

struct ViewportColors {
	ViewportColors ();
	~ViewportColors ();

	// set of color options
	GLfloat node[3];
	GLfloat selected[3];

	GLfloat wireframe[3];
	GLfloat surface[3];

	GLfloat tetrahedron4[3];
	GLfloat tetrahedron10[3];
	GLfloat hexahedron8[3];
	GLfloat hexahedron20[3];
	GLfloat hexahedron27[3];
	GLfloat prism6[3];

	GLfloat arrow[3];
	
	GLfloat background[3];
};


#endif
