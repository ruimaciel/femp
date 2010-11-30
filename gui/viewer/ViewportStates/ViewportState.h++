#ifndef VIEWPORT_STATE_HPP
#define VIEWPORT_STATE_HPP


#include <QMouseEvent>

#include "../../fem/Model.h++"
#include "../ViewportData.h++"
#include "../ViewportColors.h++"
#include "../Camera.h++"
#include "../SceneGraph.h++"


class ModelViewport;

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
		Initializes everything needed in a ViewportState once the focus is placed on it
		*/
		virtual void initialize(ModelViewport *mv) = 0;

		/*
		Adds to the scenegraph all the objects being rendered 
		*/
		virtual void populateScenegraph(ModelViewport *mv) = 0;

		/*
		Routine which will paint each OpenGL scene
		*/
		virtual void paintGL(ModelViewport *mv)	= 0;
		virtual void mousePressEvent(ModelViewport *mv, QMouseEvent *event) = 0;
		virtual void mouseMoveEvent(ModelViewport *mv, QMouseEvent *event);
};


#endif
