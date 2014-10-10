#ifndef POSTPROCESSING_VIEWPORT_HPP
#define POSTPROCESSING_VIEWPORT_HPP


#include <sigc++/sigc++.h> 	// to side step a compiler error caused by a conflict with Qt and libsigc++
#include <QWidget>
#include <QGLWidget>

#include "../Project.h++"
#include <libfemp/Model.h++>
#include <libfemp/AnalysisResult.h++>
#include <libfemp/ElementResults/ResultsRanges.h++>
#include <libfemp/LinearAnalysis.h++>

#include "../MdiWindowProperties.h++"

#include "BaseViewport.h++"
#include "Camera.h++"
#include "ViewportColors.h++"
#include "DisplayOptions.h++"

#include "ViewportData.h++"

#include "ViewportStates/ViewportState.h++"	// for the vieport's state pattern base class

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
	fem::AnalysisResult<double> *m_analysis_result;
	VPStateDisplacements 	m_vp_state_displacements;
	VPStateGradients	m_vp_state_gradients;

public:
	PostprocessingViewport(fem::Project &project, fem::AnalysisResult<double> &result, fem::ResultsRanges<double> &ranges, QWidget *parent = NULL);
	~PostprocessingViewport();

	/**
	Sets this viewport to represent a given analysis result 
	@param	result	an analysis result
	**/
	void setAnalysisResult(fem::AnalysisResult<double> &result);

	void setResultsRanges(fem::ResultsRanges<double> &ranges);

	// set the viewport state
	void showDisplacements();
	void showStrain11();
	void showStrain22();
	void showStrain33();
	void showStrain12();
	void showStrain23();
	void showStrain13();

	void showStress11();
	void showStress22();
	void showStress33();
	void showStress12();
	void showStress23();
	void showStress13();

	void showVonMises();

};

#endif
