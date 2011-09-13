#ifndef VIEWPORT_COLORS_HPP
#define VIEWPORT_COLORS_HPP

#include <sigc++/sigc++.h> 	// to side step a compiler error caused by a conflict with Qt and libsigc++
#include <GL/gl.h>


/**
Stores all the color information which is used by the program
**/
struct ViewportColors 
{
	ViewportColors ();

	// set of color options
	GLfloat node[4];	// node colors
	GLfloat restraints[4];	// color for the cinematic restraints
	GLfloat selected[4];

	GLfloat wireframe[4];
	GLfloat surface[4];
	GLfloat original_surface[4];	// displacement: for surfaces for the model in the original configuration

	GLfloat arrow[4];
	
	GLfloat background[4];

	// field colors
	GLfloat field_maximum_positive[4];
	GLfloat field_semi_maximum_positive[4];
	GLfloat field_neutral[4];
	GLfloat field_maximum_negative[4];
	GLfloat field_semi_maximum_negative[4];
};


#endif
