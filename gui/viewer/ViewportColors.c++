#include "ViewportColors.h++"


ViewportColors::ViewportColors ()
{
	// set helper function
	#define INIT_ELEMENT(ELEMENT, R, G, B) \
	ELEMENT[0] = R, ELEMENT[1] = G, ELEMENT[2] = B; ELEMENT[3] = 1; ELEMENT[3] = 1;


	INIT_ELEMENT(node	, 	0,	0.5,	0);
	INIT_ELEMENT(restraints	, 	0,	0.5,	0);
	INIT_ELEMENT(selected	, 	1,	0,	0);
	INIT_ELEMENT(wireframe	,	0,	0.5,	0);
	INIT_ELEMENT(surface	, 	0,	0.5,	0);
	INIT_ELEMENT(original_surface,	0,	0.5,	0); original_surface[3] = 0.3;

	INIT_ELEMENT(arrow	, 	1, 	0, 	0);

	INIT_ELEMENT(background, 0.52,0.52,0.68);

	INIT_ELEMENT(field_maximum_positive	, 	1, 	0, 	0);
	INIT_ELEMENT(field_maximum_negative	, 	0, 	0, 	1);
	INIT_ELEMENT(field_neutral	, 	1, 	1, 	1);
	#undef INIT_ELEMENT
}


