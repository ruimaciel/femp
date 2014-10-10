#ifndef MODEL_VIEWPORT_HPP
#define MODEL_VIEWPORT_HPP


#include <sigc++/sigc++.h> 	// to side step a compiler error caused by a conflict with Qt and libsigc++
#include <QWidget>
#include <QGLWidget>

#include "../MdiWindowProperties.h++"

#include "Project.h++"

#include <libfemp/Model.h++>
#include <libfemp/LinearAnalysis.h++>

#include "BaseViewport.h++"
#include "Camera.h++"
#include "ViewportColors.h++"
#include "DisplayOptions.h++"

#include "ViewportData.h++"

#include "ViewportStates/ViewportState.h++"	// for the vieport's state pattern base class
#include "ViewportStates/VPStateModel.h++"



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

	// set the viewport state
	void showModel();

};

#endif
