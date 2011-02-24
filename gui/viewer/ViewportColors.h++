#ifndef VIEWPORT_COLORS_HPP
#define VIEWPORT_COLORS_HPP

#include <GL/gl.h>

struct ViewportColors {
	ViewportColors ();
	~ViewportColors ();

	// set of color options
	GLfloat node[4];
	GLfloat selected[4];

	GLfloat wireframe[4];
	GLfloat surface[4];
	GLfloat original_surface[4];	// displacement: for surfaces for the model in the original configuration

	GLfloat tetrahedron4[4];	// remove
	GLfloat tetrahedron10[4];	// remove
	GLfloat hexahedron8[4];	// remove
	GLfloat hexahedron20[4];	// remove
	GLfloat hexahedron27[4];	// remove
	GLfloat prism6[4];

	GLfloat arrow[4];
	
	GLfloat background[4];
};


#endif
