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
	GLfloat original_surface[4];	// displacement: for surfaces for the model in the original configuration

	GLfloat tetrahedron4[3];	// remove
	GLfloat tetrahedron10[3];	// remove
	GLfloat hexahedron8[3];	// remove
	GLfloat hexahedron20[3];	// remove
	GLfloat hexahedron27[3];	// remove
	GLfloat prism6[3];

	GLfloat arrow[3];
	
	GLfloat background[3];
};


#endif
