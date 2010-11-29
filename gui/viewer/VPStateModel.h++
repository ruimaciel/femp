#ifndef VIEWPORT_STATE_MODEL_HPP
#define VIEWPORT_STATE_MODEL_HPP


#include <QMouseEvent>

#include "ViewportState.h++"
#include "ViewportData.h++"
#include "ViewportColors.h++"


class ModelViewport;

/*
A pattern for the State pattern which is used to render the model space
*/
class VPStateModel
	:public ViewportState
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
		a temporary brute force solution to sidestep the scenegraph
		to be replaced with the scenegraph code
		*/
		void crudePaintHack(ModelViewport *mv);

		void renderLine3(const fem::point &p1, const fem::point &p2, const fem::point &p3, int partitions = 10);
		void renderQuad4(const fem::point &p1, const fem::point &p2,const fem::point &p3,const fem::point &p4, int partitions = 4);
		void renderQuad8(const fem::point &p1, const fem::point &p2, const fem::point &p3, const fem::point &p4,const fem::point &p5, const fem::point &p6, const fem::point &p7, const fem::point &p8, int partitions = 8);
		void renderQuad9(const fem::point &p1, const fem::point &p2, const fem::point &p3, const fem::point &p4,const fem::point &p5, const fem::point &p6, const fem::point &p7, const fem::point &p8, const fem::point &p9, int partitions = 8);
		void renderTriangle3(const fem::point &p1, const fem::point &p2,const fem::point &p3, int partitions = 4);
		void renderTriangle6(const fem::point &p1, const fem::point &p2,const fem::point &p3,const fem::point &p4, const fem::point &p5, const fem::point &p6, int partitions = 8);

		void paintNode(ViewportData &data, GLfloat color[3], const fem::point p);

		/*
		Marks all objects which intersect with a given ray as selected
		*/
		void selectModelObjects(const fem::point &near,const fem::point &far);
};


#endif
