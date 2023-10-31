#ifndef VIEWER_POSTPROCESSINGVIEWPORT_HPP
#define VIEWER_POSTPROCESSINGVIEWPORT_HPP

// viewer includes
#include <viewer/BaseViewport.h++>
#include "ViewportStates/VPStateDisplacements.h++"
#include "ViewportStates/VPStateGradients.h++"

// gui includes
#include "Project.h++"

// libfemp includes
#include <libfemp/AnalysisResult.h++>
#include <libfemp/ElementResults/ElementResults.h++>

// Qt includes
#include <QWidget>

/**
 * QGLWidget subclass designed to represent any postprocessing being done to any
 * given model's FEM solution.
 */
class PostprocessingViewport : public BaseViewport {
	Q_OBJECT

	public:
	PostprocessingViewport(fem::Project& project, fem::AnalysisResult& result, fem::ResultsRanges<double>& ranges, QWidget* parent = nullptr);
	~PostprocessingViewport();

	/**
	 * Sets this viewport to represent a given analysis result
	 * @param	result	an analysis result
	 */
	void setAnalysisResult(fem::AnalysisResult& result);

	void setResultsRanges(fem::ResultsRanges<double>& ranges);

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

	protected:
	fem::AnalysisResult* m_analysis_result;
	VPStateDisplacements m_vp_state_displacements;
	VPStateGradients m_vp_state_gradients;
};

#endif
