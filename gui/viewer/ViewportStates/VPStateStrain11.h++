#ifndef VIEWPORT_STATE_STRAIN_11_HPP
#define VIEWPORT_STATE_STRAIN_11_HPP


#include <QMouseEvent>

#include "FieldComponent.h++"

#include "../../fem/Node.h++"
#include "ViewportState.h++"
#include "../BaseViewport.h++"
#include "../ViewportData.h++"
#include "../ViewportColors.h++"

#include "../../fem/AnalysisResult.h++"


class BaseViewport;

/*
A pattern for the State pattern which is used to render the model space
*/
class VPStateStrain11
	:public ViewportState<BaseViewport>
{
	protected:
		FieldComponent	*field;	// pointer used for a state pattern that sets which recovered field to represent

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
		Sets 
		**/
		template<typename scalar>
		void setDisplacements(fem::AnalysisResult<scalar> &);

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
