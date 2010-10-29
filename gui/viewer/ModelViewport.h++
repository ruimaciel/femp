#ifndef MODEL_VIEWPORT_HPP
#define MODEL_VIEWPORT_HPP


#include <QWidget>
#include <QGLWidget>

#include "Logs.h++"

#include "../MdiWindowProperties.h++"

#include "../fem/Model.h++"
#include "Camera.h++"
#include "ViewportColors.h++"
#include "DisplayOptions.h++"

#include "ViewportState.h++"	// for the vieport's state pattern base class
#include "VPStateModel.h++"


class ModelViewport 
	: public QGLWidget, public MdiWindowProperties
{
	Q_OBJECT

	protected:
		ViewportState	*state;	// pointer to object used for the State pattern
		VPStateModel	StateModel;	// rendering state: Model

	public:
		ModelViewport(fem::Model *model, QWidget *parent = NULL);
		~ModelViewport();

		void setColors(ViewportColors *colors);

		QSize minimumSizeHint() const;
		QSize sizeHint() const;


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

	public:
		DisplayOptions display_options;	// options list to be used by the render routine


	protected:
		void normalizeAngle(int *angle);

		Camera camera;	// transition to a camera class
		ViewportColors *colors;	// color definitions

		float zoom;		// drawing zoom, used to zoom
		float aspect_ratio;	// window aspect ratio
		float node_scale;	// the scale used by the nodes, reset when a window resizes

		fem::Model *model;

		QPoint lastPos;
};

#endif
