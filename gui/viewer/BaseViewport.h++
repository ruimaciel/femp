#ifndef BASE_VIEWPORT_HPP
#define BASE_VIEWPORT_HPP

#include <assert.h>

#include <QGLWidget>

#include "../MdiWindowProperties.h++"

#include "../fem/Model.h++"

#include "BaseViewport.h++"
#include "Camera.h++"
#include "ViewportColors.h++"
#include "DisplayOptions.h++"

#include "ViewportData.h++"

#include "ViewportStates/ViewportState.h++"	// for the vieport's state pattern base class


/*
Base class for all Qt widgets that provide an opengl viewports to render the model 
*/
class BaseViewport 
	: public QGLWidget
{
	Q_OBJECT

	public:
		ViewportData viewport_data;
		ViewportColors colors;	// color definitions
		DisplayOptions display_options;	// options list to be used by the render routine

		fem::Model *model;

		ViewportState<BaseViewport>	*state;	// pointer to object used for the State pattern

	public:
		BaseViewport(fem::Model *model, QWidget *parent);


		void setColors(ViewportColors &new_colors);

		QSize minimumSizeHint() const;
		QSize sizeHint() const;

		/*
		Generic method to implement a state pattern to render variants of the same model (i.e., XX tension, YY tension...)
		*/
		template <class NewState>
		void setState(NewState *);


	public Q_SLOTS:
		void setXRotation(int angle);
		void setYRotation(int angle);
		void setZRotation(int angle);
		void setPosition(int x, int y);

	Q_SIGNALS:
		void xRotationChanged(int angle);
		void yRotationChanged(int angle);
		void zRotationChanged(int angle);

	protected:
		void initializeGL();
		void resizeGL(int width, int height);
		void paintGL();

		// routines to handle input
		void mousePressEvent(QMouseEvent *event);
		void mouseMoveEvent(QMouseEvent *event);
		void wheelEvent(QWheelEvent *event);
		void keyPressEvent ( QKeyEvent * event );

		void setState(ViewportState<BaseViewport> *new_state);

	protected:
		void normalizeAngle(int *angle);

};


#endif
