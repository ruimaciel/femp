#ifndef DISPLACEMENTS_VIEWPORT_HPP
#define DISPLACEMENTS_VIEWPORT_HPP


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
#include "ViewportStates/VPStateDisplacements.h++"

#include "../fem/LinearAnalysis.h++"


class DisplacementsViewport 
	: public QGLWidget, public MdiWindowProperties
{
	Q_OBJECT

	protected:
		fem::AnalysisResult<double> *analysis_result;

	public:
		ViewportData viewport_data;
		ViewportColors colors;	// color definitions
		DisplayOptions display_options;	// options list to be used by the render routine

		fem::Model *model;

		ViewportState<DisplacementsViewport>	*state;	// pointer to object used for the State pattern

	public:
		DisplacementsViewport(fem::Model *model, fem::AnalysisResult<double> &analysis, QWidget *parent = NULL);
		~DisplacementsViewport();

		void setColors(ViewportColors &new_colors);

		QSize minimumSizeHint() const;
		QSize sizeHint() const;


		template <class NewState>
		void setState(NewState *);

		/*
		sets if the element nodes are visible
		@param	state	true if nodes should be visible, false if they shouldn't be rendered
		*/
		void setNodeVisibility(bool state);
		void setSurfaceVisibility(bool state);


	public Q_SLOTS:
		void setXRotation(int angle);
		void setYRotation(int angle);
		void setZRotation(int angle);
		void setPosition(int x, int y);

		// set the viewport state
		// void showModel();
		void showDisplacements(fem::AnalysisResult<double> &);

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

	protected:
		void normalizeAngle(int *angle);
};

#endif
