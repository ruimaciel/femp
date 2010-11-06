#ifndef VIEWPORT_STATE_HPP
#define VIEWPORT_STATE_HPP


#include <QMouseEvent>

#include "../fem/Model.h++"
#include "ViewportData.h++"
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
		virtual void paintGL(fem::Model *model, ViewportData &data, ViewportColors &colors) = 0;
		virtual void mousePressEvent(QMouseEvent *event, ViewportData &data) = 0;
		virtual void mouseMoveEvent(QMouseEvent *event, ViewportData &data);
};


#endif
