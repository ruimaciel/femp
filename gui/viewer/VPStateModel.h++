#ifndef VIEWPORT_STATE_MODEL_HPP
#define VIEWPORT_STATE_MODEL_HPP


#include <QMouseEvent>

#include "ViewportState.h++"

/*
A pattern for the State pattern which is used to render the model space
*/
class VPStateModel
	:public ViewportState
{
	public:
		VPStateModel();
		~VPStateModel();

		void paintGL(fem::Model &);
		void mousePressEvent(QMouseEvent *event);
		// void mouseMoveEvent(QMouseEvent *event);
};


#endif
