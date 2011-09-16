#ifndef VIEWPORT_DATA_HPP
#define VIEWPORT_DATA_HPP


#include <sigc++/sigc++.h> 	// to side step a compiler error caused by a conflict with Qt and libsigc++
#include <list>
#include <QPoint>

#include "Camera.h++"
#include "../fem/ElementResults/Strains.h++"
#include "../fem/ElementResults/Stresses.h++"

/*
Struct intended to encapsulate all viewport data to be used by all ViewportState subclasses
The main purpose is to keep stuff such as camera info, zoom and window aspect ratio common to all viewport states
*/
struct ViewportData
{
	ViewportData();

	Camera camera;	// transition to a camera class

	float zoom;		// drawing zoom, used to zoom
	float aspect_ratio;	// window aspect ratio
	float node_scale;	// the scale used by the nodes, reset when a window resizes

	float modelview[16];	// opengl modelview matrix

	QPoint lastPos;

	std::list<size_t> selected_node_list;

	//gradient values
	fem::Strains<float>	max_strains, min_strains;
	fem::Stresses<float>	max_stresses, min_stresses;
	float max_von_mises, min_von_mises;

	void reset();
};


#endif
