#ifndef GLDISPLACEMENTSWIDGET_HPP
#define GLDISPLACEMENTSWIDGET_HPP

#include <sigc++/sigc++.h> 	// to side step a compiler error caused by a conflict with Qt and libsigc++
#include <QWheelEvent>

#include <map>

#include "glBaseWidget.h++"
#include "fem/Node.h++"
#include "MdiWindowProperties.h++"


/*
OpenGL widget that renders the model in a deformed position
*/
class GLDisplacementsWidget 
	: public GLBaseWidget, public MdiWindowProperties
{
	Q_OBJECT

	public:
		GLDisplacementsWidget( Document *document, ProcessedModel *, QWidget *parent = 0);
		~GLDisplacementsWidget();

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

		ProcessedModel *processed_model;

		// displacements
		std::map<size_t, fem::Node>	displacements_map;	// maps the relative displacement of each DoF
		float displacements_scale;
};

#endif
