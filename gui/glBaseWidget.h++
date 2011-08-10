#ifndef GLBASE_WIDGET_HPP
#define GLBASE_WIDGET_HPP


#include <sigc++/sigc++.h> 	// to side step a compiler error caused by a conflict with Qt and libsigc++
#include <QGLWidget>

#include "Logs.h++"

#include "Document.h++"
#include "Camera.h++"
#include "ViewportColors.h++"
#include "DisplayOptions.h++"


class GLBaseWidget 
	: public QGLWidget
{
	Q_OBJECT

	public:
		GLBaseWidget(Document *document, QWidget *parent = 0);
		~GLBaseWidget();

		void setDocument(Document *);	// sets a reference to a document object
		void setColors(ViewportColors *colors);

		QSize minimumSizeHint() const;
		QSize sizeHint() const;

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
		void resizeGL(int width, int height);
		virtual void paintGL() = 0;

		void paintArrow(const fem::point &p, const fem::point &direction);

		virtual void generateDisplayLists() = 0;

	public:
		DisplayOptions display_options;	// options list to be used by the render routine


	protected:
		void normalizeAngle(int *angle);

		Camera camera;	// transition to a camera class
		ViewportColors *colors;	// color definitions
		QColor qtPurple;

		float zoom;		// drawing zoom, used to zoom
		float aspect_ratio;	// window aspect ratio
		float node_scale;	// the scale used by the nodes, reset when a window resizes

		Document *document;

		// display list indices
		GLuint dl_nodes;
		GLuint dl_faces;
		GLuint dl_wireframe;
};

#endif
