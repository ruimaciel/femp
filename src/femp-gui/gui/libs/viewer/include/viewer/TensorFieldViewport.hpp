#ifndef GUI_VIEWER_TENSORFIELDVIEWPORT_HPP
#define GUI_VIEWER_TENSORFIELDVIEWPORT_HPP

// viewer includes
#include <viewer/BaseViewport.hpp>

#include "ViewportStates/VPStateTensorFields.hpp"

// gui includes
#include "Project.hpp"

// libfemp includes
#include <libfemp/AnalysisResult.hpp>
#include <libfemp/ElementResults/ResultsRanges.hpp>

// Qt includes
#include <QWidget>

/**
 * QGLWidget subclass designed to represent any postprocessing being done to any
 * given model's FEM solution.
 */
class TensorFieldViewport : public BaseViewport {
	Q_OBJECT

	public:
	TensorFieldViewport(fem::Project& project, fem::AnalysisResult& result, fem::ResultsRanges<double>& ranges, QWidget* parent = nullptr);
	~TensorFieldViewport();

	/**
	 * Sets this viewport to represent a given analysis result
	 * @param	result	an analysis result
	 */
	void setAnalysisResult(fem::AnalysisResult& result);

	void setResultsRanges(fem::ResultsRanges<double>& ranges);

	/**
	 * Set the viewport state
	 */
	void showTensionField();

	void showNegativePrincipalStressesVisibility(bool state);
	void showPositivePrincipalStressesVisibility(bool state);

	protected:
	fem::AnalysisResult* m_analysis_result;
	VPStateTensorFields m_vp_state_tensor_fields;
};

#endif
