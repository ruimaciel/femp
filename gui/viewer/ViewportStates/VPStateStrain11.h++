#ifndef VIEWPORT_STATE_STRAIN_11_HPP
#define VIEWPORT_STATE_STRAIN_11_HPP


#include <sigc++/sigc++.h> 	// to side step a compiler error caused by a conflict with Qt and libsigc++
#include <QMouseEvent>

#include "FieldComponent.h++"

#include "../../fem/Node.h++"
#include "ViewportState.h++"
#include "../BaseViewport.h++"
#include "../ViewportData.h++"
#include "../ViewportColors.h++"

#include "../SceneGraphComponents/ElementRepresentationPolicy/ElementRepresentationFlyweightFactory.h++"
#include "../SceneGraphComponents/DisplacementsRepresentationPolicy/DisplacementsPolicy.h++"
#include "../SceneGraphComponents/ElementFactory.h++"



class BaseViewport;

/*
A pattern for the State pattern which is used to render the model space
*/
class VPStateStrain11
	:public ViewportState<BaseViewport>
{
	protected:
		ElementRepresentationFlyweightFactory	m_element_representation_factory;
		DisplacementsPolicy 	m_displacements;	// the displacements view renders displacements
		SGC::ElementFactory	m_factory;

	public:
		VPStateStrain11();
		~VPStateStrain11();

		void initialize(BaseViewport *mv);
		void populateScenegraph(BaseViewport *mv);
		void paintGL(BaseViewport *mv);
		void mousePressEvent(BaseViewport *mv, QMouseEvent *event);
		// void mouseMoveEvent(QMouseEvent *event);
		void keyPressEvent ( BaseViewport *mv, QKeyEvent * event );


		/**
		Sets which field this viewport will render
		**/
		void setField(FieldComponent *field);


	protected:
		/*
		Marks all objects which intersect with a given ray as selected
		*/
		void selectModelObjects(const fem::point &near,const fem::point &far);
};

#endif
