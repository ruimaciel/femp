#ifndef VIEWPORT_STATE_TENSION_FIELDS_HPP
#define VIEWPORT_STATE_TENSION_FIELDS_HPP


#include <sigc++/sigc++.h> 	// to side step a compiler error caused by a conflict with Qt and libsigc++
#include <QMouseEvent>

#include "ViewportState.h++"
#include "../BaseViewport.h++"
#include "../ViewportData.h++"
#include "../ViewportColors.h++"

#include "../SceneGraphComponents/ElementRepresentationPolicy/TensionFieldRepresentationPolicy.h++"
#include "../SceneGraphComponents/DisplacementsRepresentationPolicy/DisplacementsPolicy.h++"
#include "../SceneGraphComponents/SceneComponentFactory.h++"


class BaseViewport;

/*
A pattern for the State pattern which is used to render the tension fields 
*/
class VPStateTensionFields
	:public ViewportState
{
protected:
	TensionFieldRepresentationPolicy	m_tension_representation;
	DisplacementsPolicy			m_displacements;	// the displacements view renders displacements
	SGC::SceneComponentFactory		m_factory;

public:
	VPStateTensionFields();
	~VPStateTensionFields();

	void initialize(BaseViewport *mv);
	void populateScenegraph(BaseViewport *mv);

	/**
	  Configures the viewport to render the scene according to new_result
	 **/
	void setAnalysisResult(fem::AnalysisResult<double> &new_result);
	void setResultsRanges(fem::ResultsRanges<double> &ranges);

	void setDisplacementsScale(float new_scale);

	void paintGL(BaseViewport *mv);
	void mousePressEvent(BaseViewport *mv, QMouseEvent *event);
	// void mouseMoveEvent(QMouseEvent *event);
	void keyPressEvent ( BaseViewport *mv, QKeyEvent * event );

	void showNegativePrincipalStressesVisibility(bool state);
	void showPositivePrincipalStressesVisibility(bool state);

};

#endif
