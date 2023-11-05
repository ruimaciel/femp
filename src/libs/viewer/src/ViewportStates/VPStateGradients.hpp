#ifndef FEMP_VIEWER_VPSTATEGRADIENTS_HPP
#define FEMP_VIEWER_VPSTATEGRADIENTS_HPP

#include <QMouseEvent>
#include <options/Options.hpp>
#include <viewer/ViewportData.hpp>

#include "../SceneGraphComponents/DisplacementsRepresentationPolicy/DisplacementsPolicy.hpp"
#include "../SceneGraphComponents/ElementRepresentationPolicy/GradientFieldRepresentationPolicy.hpp"
#include "../SceneGraphComponents/SceneComponentFactory.hpp"
#include "ViewportState.hpp"

class BaseViewport;

/**
 * A pattern for the State pattern which is used to render the gradients
 * (stresses, strains...)
 */
class VPStateGradients : public ViewportState {
	protected:
	GradientFieldRepresentationPolicy m_gradient_representation;
	DisplacementsPolicy m_displacements;  // the displacements view renders displacements
	SGC::SceneComponentFactory m_factory;

	public:
	VPStateGradients();
	~VPStateGradients();

	void initialize(BaseViewport* mv);
	void populateScenegraph(BaseViewport* mv);

	/**
	 * Configures the viewport to render the scene according to new_result
	 */
	void setAnalysisResult(fem::AnalysisResult& new_result);

	void setResultsRanges(fem::ResultsRanges<double>& ranges);

	void setDisplacementsScale(float new_scale);

	/**
	 * Tweaks the way the viewport is rendered according to the current selection
	 */
	void setSelection(Selection);

	void keyPressEvent(BaseViewport* mv, QKeyEvent* event);

	public:
	// set which gradient field to render
	void renderStrains11();
	void renderStrains22();
	void renderStrains33();
	void renderStrains12();
	void renderStrains23();
	void renderStrains13();

	void renderStresses11();
	void renderStresses22();
	void renderStresses33();
	void renderStresses12();
	void renderStresses23();
	void renderStresses13();

	void renderVonMises();
};

#endif
