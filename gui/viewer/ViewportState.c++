#include "ViewportState.h++"

#include <QtOpenGL>

#include "../point.h++"


ViewportState::ViewportState()
{
}


ViewportState::~ViewportState()
{
}


void ViewportState::mousePressEvent(QMouseEvent *event)
{
	lastPos = event->pos();
	// process left clicks
	if(event->buttons() & Qt::LeftButton)
	{
		fem::point near, far;
		QPoint pos = event->pos();
		GLdouble modelview[16];
		GLdouble projection[16];
		GLint viewport[4];

		glGetDoublev(GL_MODELVIEW_MATRIX, modelview);
		glGetDoublev(GL_PROJECTION_MATRIX, projection);
		glGetIntegerv(GL_VIEWPORT, viewport);
		gluUnProject(pos.x(), viewport[3]-pos.y(), 0, modelview, projection, viewport, &near.data[0], &near.data[1], &near.data[2]);
		gluUnProject(pos.x(), viewport[3]-pos.y(), 1, modelview, projection, viewport, &far.data[0], &far.data[1], &far.data[2]);

		// push the line
		// selectModelObjects(near, far); 	//TODO finish this

	}
}


void ViewportState::mouseMoveEvent(QMouseEvent *event)
{
	int dx = event->x() - lastPos.x();
	int dy = event->y() - lastPos.y();

	if (event->buttons() & Qt::LeftButton) 
	{
		//TODO set action for left click button
	} else if (event->buttons() & Qt::RightButton) 
	{
		camera.rotation.data[0] += dy;
		camera.rotation.data[1] += dx;
		/*
		setXRotation(camera.rotation.data[0] + dy);
		setYRotation(camera.rotation.data[1] + dx);
		*/
	}

	lastPos = event->pos();
}


