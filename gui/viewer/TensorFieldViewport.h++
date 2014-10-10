#ifndef TENSOR_FIELD_VIEWPORT_HPP
#define TENSOR_FIELD_VIEWPORT_HPP


#include <sigc++/sigc++.h> 	// to side step a compiler error caused by a conflict with Qt and libsigc++
#include <QWidget>
#include <QGLWidget>

#include "../MdiWindowProperties.h++"

#include "../Project.h++"
#include <libfemp/Model.h++>

#include <libfemp/AnalysisResult.h++>
#include <libfemp/ElementResults/ResultsRanges.h++>
#include <libfemp/LinearAnalysis.h++>

#include "BaseViewport.h++"
#include "Camera.h++"
#include "ViewportColors.h++"
#include "DisplayOptions.h++"

#include "ViewportData.h++"

#include "ViewportStates/ViewportState.h++"	// for the vieport's state pattern base class

#include "ViewportStates/VPStateDisplacements.h++"
#include "ViewportStates/VPStateGradients.h++"
#include "ViewportStates/VPStateTensorFields.h++"


/**
QGLWidget subclass designed to represent any postprocessing being done to any given model's FEM solution.
**/
class TensorFieldViewport 
	: public BaseViewport
{
	Q_OBJECT

protected:
	fem::AnalysisResult<double> *m_analysis_result;
	VPStateTensorFields	m_vp_state_tensor_fields;

public:
	TensorFieldViewport(fem::Project &project, fem::AnalysisResult<double> &result, fem::ResultsRanges<double> &ranges, QWidget *parent = NULL);
	~TensorFieldViewport();

	/**
	Sets this viewport to represent a given analysis result 
	@param	result	an analysis result
	**/
	void setAnalysisResult(fem::AnalysisResult<double> &result);

	void setResultsRanges(fem::ResultsRanges<double> &ranges);

	// set the viewport state
	void showTensionField();

	void showNegativePrincipalStressesVisibility(bool state);
	void showPositivePrincipalStressesVisibility(bool state);

};

#endif
