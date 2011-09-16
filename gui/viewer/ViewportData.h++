#ifndef VIEWPORT_DATA_HPP
#define VIEWPORT_DATA_HPP


#include <sigc++/sigc++.h> 	// to side step a compiler error caused by a conflict with Qt and libsigc++
#include <list>
#include <QPoint>

#include "Camera.h++"


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

	void reset();
};


#endif
