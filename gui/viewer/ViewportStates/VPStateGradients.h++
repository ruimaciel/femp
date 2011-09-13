#ifndef VIEWPORT_STATE_GRADIENTS_HPP
#define VIEWPORT_STATE_GRADIENTS_HPP


#include <sigc++/sigc++.h> 	// to side step a compiler error caused by a conflict with Qt and libsigc++
#include <QMouseEvent>

#include "ViewportState.h++"
#include "../BaseViewport.h++"
#include "../ViewportData.h++"
#include "../ViewportColors.h++"

#include "../SceneGraphComponents/ElementRepresentationPolicy/GradientFieldRepresentationPolicy.h++"
#include "../SceneGraphComponents/DisplacementsRepresentationPolicy/DisplacementsPolicy.h++"
#include "../SceneGraphComponents/SceneComponentFactory.h++"


class BaseViewport;

/*
A pattern for the State pattern which is used to render the gradients (stresses, strains...)
*/
class VPStateGradients
	:public ViewportState<BaseViewport>
{
protected:
	GradientFieldRepresentationPolicy	m_gradient_representation;
	DisplacementsPolicy			m_displacements;	// the displacements view renders displacements
	SGC::SceneComponentFactory		m_factory;

public:
	VPStateGradients();
	~VPStateGradients();

	void initialize(BaseViewport *mv);
	void populateScenegraph(BaseViewport *mv);

	/**
	  Configures the viewport to render the scene according to new_result
	 **/
	void setAnalysisResult(fem::AnalysisResult<double> &new_result);

	void setDisplacementsScale(float new_scale);

	/**
	Tweaks the way the viewport is rendered according to the current selection
	**/
	void setSelection(Selection);

	void paintGL(BaseViewport *mv);
	void mousePressEvent(BaseViewport *mv, QMouseEvent *event);
	// void mouseMoveEvent(QMouseEvent *event);
	void keyPressEvent ( BaseViewport *mv, QKeyEvent * event );

public:
	// set which gradient field to render
	void renderStrains11();
	void renderStrains22();
	void renderStrains33();
	void renderStrains12();
	void renderStrains23();
	void renderStrains13();

	void renderVonMises();

};

#endif
