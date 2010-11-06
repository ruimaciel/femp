#include "ViewportState.h++"

#include <QtOpenGL>

#include "../point.h++"


ViewportState::ViewportState()
{
}


ViewportState::~ViewportState()
{
}


void ViewportState::mouseMoveEvent(QMouseEvent *event, ViewportData &data)
{
	int dx = event->x() - data.lastPos.x();
	int dy = event->y() - data.lastPos.y();

	if (event->buttons() & Qt::LeftButton) 
	{
		//TODO set action for left click button
	} else if (event->buttons() & Qt::RightButton) 
	{
		data.camera.rotation.data[0] += dy/pow(2,data.zoom);
		data.camera.rotation.data[1] += dx/pow(2,data.zoom);
	}

	data.lastPos = event->pos();
}


