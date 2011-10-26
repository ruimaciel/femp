#ifndef MODEL_VIEWPORT_HPP
#define MODEL_VIEWPORT_HPP


#include <sigc++/sigc++.h> 	// to side step a compiler error caused by a conflict with Qt and libsigc++
#include <QWidget>
#include <QGLWidget>

#include "Logs.h++"

#include "../MdiWindowProperties.h++"

#include "../fem/Project.h++"
#include "../fem/Model.h++"

#include "BaseViewport.h++"
#include "Camera.h++"
#include "ViewportColors.h++"
#include "DisplayOptions.h++"

#include "ViewportData.h++"

#include "ViewportStates/ViewportState.h++"	// for the vieport's state pattern base class
#include "ViewportStates/VPStateModel.h++"

#include "../fem/LinearAnalysis.h++"


/**
The viewport class which is designed to render the model and enact changes on it
**/
class ModelViewport 
	: public BaseViewport
{
	Q_OBJECT

protected:
	VPStateModel 	m_vp_state_model;

public:
	ModelViewport(fem::Project &project, QWidget *parent = NULL);
	~ModelViewport();

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
	void paintGL();

	// routines to handle input
	void mousePressEvent(QMouseEvent *event);
	void mouseMoveEvent(QMouseEvent *event);
	void wheelEvent(QWheelEvent *event);
	void keyPressEvent ( QKeyEvent * event );
};

#endif
