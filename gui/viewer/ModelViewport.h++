#ifndef MODEL_VIEWPORT_HPP
#define MODEL_VIEWPORT_HPP


#include <QWidget>
#include <QGLWidget>

#include "Logs.h++"

#include "../MdiWindowProperties.h++"

#include "../fem/Model.h++"

#include "BaseViewport.h++"
#include "Camera.h++"
#include "ViewportColors.h++"
#include "DisplayOptions.h++"

#include "ViewportData.h++"

#include "SceneGraph.h++"
#include "ViewportStates/ViewportState.h++"	// for the vieport's state pattern base class
#include "ViewportStates/VPStateModel.h++"
#include "ViewportStates/VPStateDisplacements.h++"

#include "../fem/LinearAnalysis.h++"


class ModelViewport 
	: public BaseViewport
{
	Q_OBJECT

	public:
		ViewportState<BaseViewport>	*state;	// pointer to object used for the State pattern

	public:
		ModelViewport(fem::Model *model, QWidget *parent = NULL);
		~ModelViewport();

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
		void showModel();

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

		void normalizeAngle(int *angle);
};

#endif
