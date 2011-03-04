#ifndef DISPLAY_OPTIONS_HPP
#define DISPLAY_OPTIONS_HPP


#include "fem/Model.h++"

/** 
Helper class belonging to glwidget (a has-a relationship) that states what model properties should be rendered
**/

struct DisplayOptions {
	fem::LoadPattern	*load_pattern;	//	pointer to the load pattern to be displayed

	// boolean
	unsigned int nodes:		1;
	unsigned int surfaces:		1;

	unsigned int nodal_forces: 	1;
	unsigned int surface_forces: 	1;
	unsigned int domain_forces: 	1;
	unsigned int nodal_displacements: 	1;

	DisplayOptions();
	~DisplayOptions();

	void setDefaultOptions();
};

#endif
