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

#include "ViewportData.h++"

#include "ViewportStates/ViewportState.h++"	// for the vieport's state pattern base class
#include "ViewportStates/VPStateModel.h++"
#include "ViewportStates/VPStateDisplacements.h++"

#include "../fem/LinearAnalysis.h++"


class ModelViewport 
	: public QGLWidget, public MdiWindowProperties
{
	Q_OBJECT

	public:
		ViewportData viewport_data;
		ViewportColors colors;	// color definitions

		fem::Model *model;

		ViewportState	*state;	// pointer to object used for the State pattern

	public:
		ModelViewport(fem::Model *model, QWidget *parent = NULL);
		~ModelViewport();

		void setColors(ViewportColors &new_colors);

		QSize minimumSizeHint() const;
		QSize sizeHint() const;


		template <class NewState>
		void setState(NewState *);


	public Q_SLOTS:
		void setXRotation(int angle);
		void setYRotation(int angle);
		void setZRotation(int angle);
		void setPosition(int x, int y);

		void showDisplacements(fem::LinearAnalysis<double> &);

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
};

#endif
