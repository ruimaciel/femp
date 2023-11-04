#ifndef GUI_DISPLAYOPTIONS_HPP
#define GUI_DISPLAYOPTIONS_HPP

/**
Helper class belonging to glwidget (a has-a relationship) that states what model
properties should be rendered
**/
struct DisplayOptions {
	// boolean
	unsigned int nodes : 1;
	unsigned int node_restrictions : 1;
	unsigned int surfaces : 1;

	unsigned int nodal_forces : 1;
	unsigned int surface_forces : 1;
	unsigned int domain_forces : 1;
	unsigned int nodal_displacements : 1;

	unsigned int triangle_wireframe : 1;  // renders a wireframe bordering the
										  // OpenGL triangles
	unsigned int shading : 1;			  // renders surfaces with Gouraud shading

	DisplayOptions();
};

#endif
