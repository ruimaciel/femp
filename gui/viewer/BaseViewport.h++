#ifndef BASE_VIEWPORT_HPP
#define BASE_VIEWPORT_HPP

#include <assert.h>

#include <QGLWidget>

#include "../MdiWindowProperties.h++"

#include "../fem/Project.h++"
#include "../fem/Model.h++"
#include "../fem/AnalysisResult.h++"

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

		fem::Project *project;

		ViewportState<BaseViewport>	*state;	// pointer to object used for the State pattern

	public:
		BaseViewport(fem::Project &project, QWidget *parent);


		void setColors(ViewportColors &new_colors);

		QSize minimumSizeHint() const;
		QSize sizeHint() const;

		/*
		Generic method to implement a state pattern to render variants of the same model (i.e., XX tension, YY tension...)
		This method:
			- allocates memory for a new state object
			- initializes the object
			- generates the scenegraph
		*/
		template <class NewState>
		void setState(NewState *);

		/**
		Method to refresh the scene
		**/
		void refresh(void);


	public Q_SLOTS:
		void setXRotation(int angle);
		void setYRotation(int angle);
		void setZRotation(int angle);
		void setPosition(double x, double y, double z);

		/**
		Configures the current viewport to render new_result
		**/
		void setAnalysisResult(fem::AnalysisResult<double> &new_result);

		void setDisplacementsScale(float scale);

		/**
		Sets the visibility state of any scenegraph group of the current viewport state
		**/
		void setRenderGoupVisibility(SceneGraph::Groups group, bool state);

	Q_SIGNALS:
		void xRotationChanged(int angle);
		void yRotationChanged(int angle);
		void zRotationChanged(int angle);
		void positionChanged( double x, double y, double z);

	protected:
		void initializeGL();
		void resizeGL(int width, int height);
		virtual void paintGL();

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
