#ifndef GL_MODEL_WIDGET_HPP
#define GL_MODEL_WIDGET_HPP

#include <QGLWidget>
#include <QWheelEvent>

#include "glBaseWidget.h++"
#include "ModelSelection.h++"
#include "MdiWindowProperties.h++"


/*
OpenGL widget that lets the user see and edit the model
*/
class GLModelWidget 
	: public GLBaseWidget, public MdiWindowProperties
{
	Q_OBJECT

	public:
		GLModelWidget(Document *document, QWidget *parent = 0);
		~GLModelWidget();

		void setNodeRadiusScale(float r)	{ node_scale = r; }

	protected:
		void paintGL();

		// surface rendering methods
		void renderLine3(const fem::point &p1, const fem::point &p2, const fem::point &p3, int partitions = 10);
		void renderQuad4(const fem::point &p1, const fem::point &p2,const fem::point &p3,const fem::point &p4, int partitions = 4);
		void renderQuad8(const fem::point &p1, const fem::point &p2, const fem::point &p3, const fem::point &p4,const fem::point &p5, const fem::point &p6, const fem::point &p7, const fem::point &p8, int partitions = 8);
		void renderQuad9(const fem::point &p1, const fem::point &p2, const fem::point &p3, const fem::point &p4,const fem::point &p5, const fem::point &p6, const fem::point &p7, const fem::point &p8, const fem::point &p9, int partitions = 8);
		void renderTriangle3(const fem::point &p1, const fem::point &p2,const fem::point &p3, int partitions = 4);
		void renderTriangle6(const fem::point &p1, const fem::point &p2,const fem::point &p3,const fem::point &p4, const fem::point &p5, const fem::point &p6, int partitions = 8);
		
		// display lists methods
		void generateDisplayLists();
		void generateNodesDisplayList();

		void mousePressEvent(QMouseEvent *event);
		void mouseMoveEvent(QMouseEvent *event);
		void wheelEvent(QWheelEvent *event);
		void keyPressEvent(QKeyEvent *event);

	private:
		// methods to render FEM elements
		void paintNode(size_t label, const fem::Node);
		void paintElement(const fem::Element &element);
		void paintWireframe(const fem::Element &element);

		// select rendered objects that intersect a given line (start point, finish point)
		void selectModelObjects(const fem::point &,const fem::point &);
		void deselectAllModelObjects();

		QPoint lastPos;

};

#endif
