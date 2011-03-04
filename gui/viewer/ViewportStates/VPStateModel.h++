#ifndef VIEWPORT_STATE_MODEL_HPP
#define VIEWPORT_STATE_MODEL_HPP


#include <QMouseEvent>

#include "ViewportState.h++"
#include "../ViewportData.h++"
#include "../ViewportColors.h++"


class ModelViewport;

/*
A pattern for the State pattern which is used to render the model space
*/
class VPStateModel
	:public ViewportState<ModelViewport>
{
	public:
		VPStateModel();
		~VPStateModel();

		void initialize(ModelViewport *mv);
		void populateScenegraph(ModelViewport *mv);
		void paintGL(ModelViewport *mv);
		void mousePressEvent(ModelViewport *mv, QMouseEvent *event);
		// void mouseMoveEvent(QMouseEvent *event);

	protected:
		/*
		Marks all objects which intersect with a given ray as selected
		*/
		void selectModelObjects(const fem::point &near,const fem::point &far);
};


#endif
