#ifndef VIEWPORT_STATE_HPP
#define VIEWPORT_STATE_HPP


#include <QMouseEvent>

#include "../fem/Model.h++"

/*
The base state pattern that is used to implement the ModelViewport's model rendering states
*/
class ViewportState
{
	public:
		ViewportState();
		~ViewportState();


		virtual void paintGL(fem::Model &) = 0;
		void mousePressEvent(QMouseEvent *event);
		// void mouseMoveEvent(QMouseEvent *event);
};


#endif
