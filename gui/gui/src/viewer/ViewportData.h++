#ifndef VIEWPORT_DATA_HPP
#define VIEWPORT_DATA_HPP

#include <QPoint>
#include <list>

#include "Camera.h++"
#include <GL/gl.h> // for GLDouble definition

/**
 * Struct intended to encapsulate all viewport data to be used by all
 * ViewportState subclasses.
 * The main purpose is to keep stuff such as camera info, zoom and window
 * aspect ratio common to all viewport states.
 */
struct ViewportData {
    ViewportData();

    Camera camera; // transition to a camera class

    float node_radius;
    float zoom; // drawing zoom, used to zoom
    int width, height;
    float aspect_ratio; // window aspect ratio
    float node_scale; // the scale used by the nodes, reset when a window resizes

    GLdouble modelview[16]; // opengl modelview matrix, needed for picking to handle mouse clicks
    GLdouble projection[16]; // opengl modelview matrix, needed for picking to handle mouse clicks

    QPoint lastPos;

    std::list<size_t> selected_node_list;

    void reset();
};

#endif
