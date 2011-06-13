#include "ViewportState.h++"

//#include <QtOpenGL>

#include "../../fem/point.h++"
#include "../ModelViewport.h++"


ViewportState::ViewportState()
{
	scale = 1.0f;
}


ViewportState::~ViewportState()
{
}


void ViewportState::setAnalysisResult(fem::AnalysisResult<double> &new_result)
{
	this->result = new_result;
}


void ViewportState::setDisplacementsScale(float new_scale)
{
	this->scale = new_scale;
}


void ViewportState::mouseMoveEvent(ModelViewport *mv, QMouseEvent *event)
{
	int dx = event->x() - mv->viewport_data.lastPos.x();
	int dy = event->y() - mv->viewport_data.lastPos.y();

	if (event->buttons() & Qt::LeftButton) 
	{
		//TODO set action for left click button
	} else if (event->buttons() & Qt::RightButton) 
	{
		mv->viewport_data.camera.rotation.data[0] += dy/pow(2,mv->viewport_data.zoom);
		mv->viewport_data.camera.rotation.data[1] += dx/pow(2,mv->viewport_data.zoom);
	}

	mv->viewport_data.lastPos = event->pos();
}


void ViewportState::keyPressEvent ( ModelViewport *mv, QKeyEvent * event )
{
	qWarning("not keypressed");
	event->ignore();
}
