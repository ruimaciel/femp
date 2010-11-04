#ifndef VIEWPORT_STATE_HPP
#define VIEWPORT_STATE_HPP


#include <QMouseEvent>

#include "../fem/Model.h++"
#include "ViewportColors.h++"
#include "Camera.h++"
#include "SceneGraph.h++"

/*
The base state pattern that is used to implement the ModelViewport's model rendering states
*/
class ViewportState
{
	protected:
		SceneGraph scenegraph;
		
	public:
		ViewportState();
		~ViewportState();


		/*
		Adds to the scenegraph all the objects being rendered 
		*/
		virtual void populateScenegraph(fem::Model *) = 0;

		/*
		Routine which will paint each OpenGL scene
		*/
		virtual void paintGL(fem::Model *model, ViewportColors &colors) = 0;

		virtual void mousePressEvent(QMouseEvent *event);
		virtual void mouseMoveEvent(QMouseEvent *event);

	
		// objects used by the renderer
		Camera camera;	// transition to a camera class

		float zoom;		// drawing zoom, used to zoom
		float aspect_ratio;	// window aspect ratio
		float node_scale;	// the scale used by the nodes, reset when a window resizes

		QPoint lastPos;
};


#endif
