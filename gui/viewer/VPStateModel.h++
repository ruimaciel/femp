#ifndef VIEWPORT_STATE_MODEL_HPP
#define VIEWPORT_STATE_MODEL_HPP


#include <QMouseEvent>

#include "ViewportState.h++"

#include "ViewportColors.h++"

/*
A pattern for the State pattern which is used to render the model space
*/
class VPStateModel
	:public ViewportState
{
	public:
		VPStateModel();
		~VPStateModel();

		void populateScenegraph(fem::Model *);
		void paintGL(fem::Model *model, ViewportColors *colors);
		void mousePressEvent(QMouseEvent *event);
		// void mouseMoveEvent(QMouseEvent *event);

	protected:
		/*
		a temporary brute force solution to sidestep the scenegraph
		to be replaced with the scenegraph code
		*/
		void crudePaintHack(fem::Model *model, ViewportColors *colors);

		void renderLine3(const fem::point &p1, const fem::point &p2, const fem::point &p3, int partitions = 10);
		void renderQuad4(const fem::point &p1, const fem::point &p2,const fem::point &p3,const fem::point &p4, int partitions = 4);
		void renderQuad8(const fem::point &p1, const fem::point &p2, const fem::point &p3, const fem::point &p4,const fem::point &p5, const fem::point &p6, const fem::point &p7, const fem::point &p8, int partitions = 8);
		void renderQuad9(const fem::point &p1, const fem::point &p2, const fem::point &p3, const fem::point &p4,const fem::point &p5, const fem::point &p6, const fem::point &p7, const fem::point &p8, const fem::point &p9, int partitions = 8);
		void renderTriangle3(const fem::point &p1, const fem::point &p2,const fem::point &p3, int partitions = 4);
		void renderTriangle6(const fem::point &p1, const fem::point &p2,const fem::point &p3,const fem::point &p4, const fem::point &p5, const fem::point &p6, int partitions = 8);

		void paintNode(fem::Model * model, size_t label, const fem::Node node);
};


#endif
