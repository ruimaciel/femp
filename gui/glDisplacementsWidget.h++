#ifndef GLDISPLACEMENTSWIDGET_HPP
#define GLDISPLACEMENTSWIDGET_HPP

#include <QGLWidget>
#include <QWheelEvent>

#include <map>

#include "fem/Model.h++"
#include "fem/Node.h++"
#include "ViewportColors.h++"
#include "Camera.h++"
#include "DisplayOptions.h++"


class GLDisplacementsWidget : public QGLWidget
{
	Q_OBJECT

	public:
		GLDisplacementsWidget( std::map<size_t, fem::Node> new_displacements_map, QWidget *parent = 0);
		~GLDisplacementsWidget();

		QSize minimumSizeHint() const;
		QSize sizeHint() const;
		void setModel(fem::Model *);	// sets a reference to a document object
		void setColors(ViewportColors *colors);
		void setNodeRadiusScale(float r)	{ node_scale = r; }

	public Q_SLOTS:
		void setXRotation(int angle);
		void setYRotation(int angle);
		void setZRotation(int angle);
		void setPosition(int x, int y);

	Q_SIGNALS:
		void xRotationChanged(int angle);
		void yRotationChanged(int angle);
		void zRotationChanged(int angle);

	protected:
		void initializeGL();
		void paintGL();
		inline void paintArrow(const fem::point &p, const fem::point &direction);
		void resizeGL(int width, int height);

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

	public:
		DisplayOptions display_options;	// options list to be used by the render routine

	private:
		void normalizeAngle(int *angle);

		// methods to render FEM elements
		void paintNode(size_t label, const fem::Node);
		void paintElement(const fem::Element &element);
		void paintWireframe(const fem::Element &element);

		// select rendered objects that intersect a given line (start point, finish point)
		void selectModelObjects(const fem::point &,const fem::point &);
		void deselectAllModelObjects();

		Camera camera;	// transition to a camera class

		QPoint lastPos;
		QColor qtPurple;

		fem::Model *model;

		float node_scale;	// the scale used by the nodes, reset when a window resizes
		float zoom;		// drawing zoom, used to zoom
		float aspect_ratio;	// window aspect ratio

		ViewportColors *colors;	// color definitions

		// display list indices
		GLuint dl_nodes;
		GLuint dl_faces;
		GLuint dl_wireframe;

		// displacements
		std::map<size_t, fem::Node>	displacements_map;	// maps the relative displacement of each DoF
		float displacements_scale;
};

#endif
