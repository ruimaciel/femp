#ifndef TENSOR_FIELD_VIEWPORT_HPP
#define TENSOR_FIELD_VIEWPORT_HPP

#include <QWidget>
#include <libfemp/AnalysisResult.h++>
#include <libfemp/ElementResults/ResultsRanges.h++>

#include "../Project.h++"
#include "BaseViewport.h++"
#include "ViewportStates/VPStateTensorFields.h++"

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
