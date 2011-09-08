#ifndef POSTPROCESSING_VIEWPORT_HPP
#define POSTPROCESSING_VIEWPORT_HPP


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

#include "../fem/LinearAnalysis.h++"

#include "ViewportStates/VPStateDisplacements.h++"
#include "ViewportStates/VPStateGradients.h++"


/**
QGLWidget subclass designed to represent any postprocessing being done to any given model's FEM solution.
**/
class PostprocessingViewport 
	: public BaseViewport
{
	Q_OBJECT

protected:
	VPStateDisplacements 	m_vp_state_displacements;
	VPStateGradients	m_vp_state_gradients;

public:
	PostprocessingViewport(fem::Project &project, QWidget *parent = NULL);
	~PostprocessingViewport();

	/*
	Sets the starting state for the supported post-processing representations
	*/
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

	/**
	Sets this viewport to represent a given analysis result 
	@param	result	an analysis result
	**/
	void setAnalysisResult(fem::AnalysisResult<double> &result);

	// set the viewport state
	void showDisplacements();
	void showStrain11();
	void showStrain22();
	void showStrain33();

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
