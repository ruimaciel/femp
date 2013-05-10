#include "ViewportColors.h++"


ViewportColors::ViewportColors ()
{
	// set helper function
	#define INIT_ELEMENT(ELEMENT, R, G, B) \
	ELEMENT[0] = R, ELEMENT[1] = G, ELEMENT[2] = B; ELEMENT[3] = 1; 


	INIT_ELEMENT(node	, 	0,	0.5,	0);
	INIT_ELEMENT(restraints	, 	0,	0,	0.5);
	INIT_ELEMENT(selected	, 	1,	0,	0);
	INIT_ELEMENT(wireframe	,	0,	0,	0.5);	//TODO set a better value
	INIT_ELEMENT(surface	, 	0,	0.5,	0);
	INIT_ELEMENT(original_surface,	0,	0.5,	0); original_surface[3] = 0.3;

	INIT_ELEMENT(arrow	, 	1, 	0, 	0);

	INIT_ELEMENT(background, 0.52,0.52,0.68);

	INIT_ELEMENT(field_maximum_positive		, 	1, 	0, 	0);	// red
	INIT_ELEMENT(field_semi_maximum_positive	, 	1, 	1, 	0);	// yellow
	INIT_ELEMENT(field_maximum_negative		, 	0, 	0, 	1);	// blue
	INIT_ELEMENT(field_semi_maximum_negative	, 	0, 	1, 	1);	// cyan
	INIT_ELEMENT(field_neutral			, 	0, 	1, 	0);
	#undef INIT_ELEMENT
}


