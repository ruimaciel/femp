#ifndef VIEWPORT_STATE_TENSOR_FIELDS_HPP
#define VIEWPORT_STATE_TENSOR_FIELDS_HPP

#include <QMouseEvent>
#include <options/Options.h++>

#include "../BaseViewport.h++"
#include "../SceneGraphComponents/DisplacementsRepresentationPolicy/NoDisplacementsPolicy.h++"
#include "../SceneGraphComponents/ElementRepresentationPolicy/StressFieldRepresentationPolicy.h++"
#include "../SceneGraphComponents/SceneComponentFactory.h++"
#include "../ViewportData.h++"
#include "ViewportState.h++"

class BaseViewport;

/**
 * A pattern for the State pattern which is used to render the tension fields
 */
class VPStateTensorFields : public ViewportState {
	protected:
	StressFieldRepresentationPolicy m_stress_field_representation;
	NoDisplacementsPolicy m_displacements;	// the displacements view renders displacements
	SGC::SceneComponentFactory m_factory;

	public:
	VPStateTensorFields();
	~VPStateTensorFields();

	void initialize(BaseViewport* mv);
	void populateScenegraph(BaseViewport* mv);

	/**
	 * Configures the viewport to render the scene according to new_result
	 */
	void setAnalysisResult(fem::AnalysisResult& new_result);
	void setResultsRanges(fem::ResultsRanges<double>& ranges);

	void keyPressEvent(BaseViewport* mv, QKeyEvent* event);

	void showNegativePrincipalStressesVisibility(bool state);
	void showPositivePrincipalStressesVisibility(bool state);
};

#endif
