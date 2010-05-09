#include <QtGui>
#include <QtOpenGL>

#include <math.h>
#include <assert.h>
#include <map>
#include <algorithm>

#include "fem/point.h++"
#include "glwidget.h++"

GLWidget::GLWidget(QWidget *parent): QGLWidget(parent)
{
	//TODO update the UI according to the active MDI subwindow

	makeCurrent();

	// initialize the camera
	camera.reset();
	camera.setCenter(0,0,-5);

	//TODO set state from program option

	setNodeRadiusScale(20);	// default node radius, scaled
	zoom = 0.0f;	// initialize the zoom, 2^zoom
	
	// initialize the dangling pointers
	document = NULL;
	colors = NULL;

	qtPurple = QColor::fromCmykF(0.39, 0.39, 0.0, 0.0);

	// starts off with perspective
	// perspective = true;

	// assign display lists
	dl_nodes = glGenLists(1);
	dl_faces = glGenLists(1);
	dl_wireframe = glGenLists(1);
}


GLWidget::~GLWidget()
{
	//TODO add cleanup code
	glDeleteLists(dl_nodes,1);
	glDeleteLists(dl_faces,1);
	glDeleteLists(dl_wireframe,1);
}


QSize GLWidget::minimumSizeHint() const
{
	return QSize(50, 50);
}


QSize GLWidget::sizeHint() const
{
	return QSize(600, 400);
}


/*
Sets which fem::Model object this widget will render
*/
void GLWidget::setDocument(Document *document)
{
	assert(document != NULL);
	this->document = document;
}


void GLWidget::setColors(ViewportColors *colors)
{
	assert(colors != NULL);
	this->colors = colors;
}


void GLWidget::setXRotation(int angle)
{
	normalizeAngle(&angle);
	camera.rotation.data[0] = angle;
	Q_EMIT xRotationChanged(angle);
	updateGL();
}


void GLWidget::setYRotation(int angle)
{
	normalizeAngle(&angle);
	camera.rotation.data[1] = angle;
	Q_EMIT yRotationChanged(angle);
	updateGL();
}


void GLWidget::setZRotation(int angle)
{
	normalizeAngle(&angle);
	camera.rotation.data[2] = angle;
	Q_EMIT zRotationChanged(angle);
	updateGL();
}


void GLWidget::setPosition(int x, int y)
{
	//TODO implement this
	camera.pos.x(-x);
	camera.pos.y(-y);
	//camera.pos.z(amount/100.0f);
	qWarning("pos: %f, %f, %f",camera.pos.x(), camera.pos.y(), camera.pos.z());
	updateGL();
}


void GLWidget::initializeGL()
{
	// set the camera position according to the nodal center
	double pos[3] = {0};
	for(std::map<size_t, fem::Node>::iterator it = document->model.node_list.begin(); it != document->model.node_list.end(); it++)
	{
		pos[0] -= it->second.x();
		pos[1] -= it->second.y();
		pos[2] -= it->second.z();
		camera.setPosition(pos[0]/document->model.node_list.size(),pos[1]/document->model.node_list.size(),pos[2]/document->model.node_list.size());
	}

	// handle opengl
	this->makeCurrent();
	GLfloat LightAmbient[]= { 0.2f, 0.2f, 0.2f, 1.0f };
	GLfloat LightDiffuse[]= { 0.7f, 0.7f, 0.7f, 1.0f };
	GLfloat LightSpecular[]= { 1.0f, 1.0f, 1.0f, 1.0f };
	GLfloat LightPosition[]= { 0.0f, 0.0f, 0.0f, 1.0f };
	GLfloat specularity[]= { 1.0f, 1.0f, 1.0f, 1.0f };
	GLint specmaterial = 60;

	qglClearColor(qtPurple.dark());
	glClearDepth(1.0f);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	glEnable(GL_CULL_FACE);

	glEnable(GL_NORMALIZE);

	// set antialias options
	glEnable(GL_POLYGON_SMOOTH);
	glEnable(GL_LINE_SMOOTH);

	glShadeModel(GL_SMOOTH);
	glMaterialfv(GL_FRONT, GL_SPECULAR, specularity);
	glMateriali(GL_FRONT, GL_SHININESS, specmaterial);

	// lighting
	// glLightModelfv(GL_LIGHT_MODEL_AMBIENT, LightAmbient);
	glLightfv(GL_LIGHT0, GL_AMBIENT, LightAmbient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, LightDiffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, LightSpecular);
	glLightfv(GL_LIGHT0, GL_POSITION, LightPosition);

	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	glEnable(GL_MAP2_VERTEX_3);	// to interpolate the elements' surfaces
	glEnable(GL_AUTO_NORMAL);


	// generate display lists
	generateDisplayLists();
}


void GLWidget::paintGL()
{
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// sets the camera position
	camera.reposition();	

	// render all nodes
	if(document)
	{
		// Render the nodes
		if( display_options.nodes )
		{
			glCallList(dl_nodes);
		}

		// render all elements
		if(display_options.surfaces)
		{
			glCallList(dl_faces);
		}

		// render all wireframe
		if(display_options.wireframe)
		{
			glCallList(dl_wireframe);
		}

		// render all optional information, if it's enabled
		if(display_options.load_pattern != NULL)
		{
			// render the nodal forces
			if(display_options.nodal_forces)
			{
				// set the color
				for(std::map<size_t,fem::NodalLoad>::iterator i = display_options.load_pattern->nodal_loads.begin(); i != display_options.load_pattern->nodal_loads.end(); i++)
				{
					//TODO draw an arrow
					paintArrow(document->model.node_list[i->first], i->second.force.director());
				}
			}

			// render the surface forces
			if(display_options.surface_forces)
			{
				//TODO implement this
			}

			// render the domain forces
			if(display_options.domain_forces)
			{
				//TODO implement this
			}

			// and finally render the nodal displacements 
			if(display_options.nodal_displacements)
			{
				for(std::map<size_t,fem::NodalDisplacement>::iterator i = display_options.load_pattern->nodal_displacements.begin(); i != display_options.load_pattern->nodal_displacements.end(); i++)
				{
					//TODO draw an arrow
					paintArrow(document->model.node_list[i->first], i->second.displacement.director());
				}
			}
		}
	}

}


void GLWidget::paintArrow(const fem::point &p, const fem::point &direction)
{
	// draw line
	glBegin(GL_LINES);
	glVertex3dv(p.data);
	glVertex3dv((p + direction).data);
	glEnd();
}


void GLWidget::resizeGL(int width, int height)
{
	aspect_ratio = qMin(width, height);
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	
	/*
	if(perspective)
		gluPerspective(45.0/pow(2,zoom), (float)width/(float)height, 0.1, 1000);
	else
		glOrtho(-(width*2)/(aspect_ratio*pow(2,zoom)), (width*2)/(aspect_ratio*pow(2,zoom)), -height*2/(aspect_ratio*pow(2,zoom)), +height*2/(aspect_ratio*pow(2,zoom)), 0.1, 1000.0);
	*/
	glOrtho(-(width*2)/(aspect_ratio*pow(2,zoom)), (width*2)/(aspect_ratio*pow(2,zoom)), -height*2/(aspect_ratio*pow(2,zoom)), +height*2/(aspect_ratio*pow(2,zoom)), 0.1, 1000.0);
	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	
	// generate display lists
	generateDisplayLists();	// put in place to preserve the aspect_ratio of certain drawing components
}


inline void GLWidget::renderLine3(const fem::point &p1, const fem::point &p2, const fem::point &p3, int partitions)
{
	glBegin(GL_LINE_STRIP); 
	for(int i = 0; i <= partitions; i++) 
	{ 
		float x = i/(float)partitions; 
		glVertex3dv( (2.0*p3*(x-0.5)*x-4.0*p2*(x-1)*x+2.0*p1*(x-1)*(x-0.5)).data); 
	} 
	glEnd();
}


inline void GLWidget::renderQuad4(const fem::point &p1, const fem::point &p2,const fem::point &p3,const fem::point &p4, int partitions)
{
	// defining temporary structures for points and normal vectors
	fem::point p_upper_row[partitions+1];
	fem::point *pu;
	fem::point n_upper_row[partitions+1];
	fem::point *nu;
	fem::point p_lower_row[partitions+1];
	fem::point *pl;
	fem::point n_lower_row[partitions+1];
	fem::point *nl;

	float x, y;
	fem::point dndx;
	fem::point dndy;

	// position the pointers
	pu = p_upper_row;
	pl = p_lower_row;

	nu = n_upper_row;
	nl = n_lower_row;

	// initialize the bottom row
	y = 0;
	for(int i = 0; i <= partitions; i++)
	{
		x = ((double)i)/partitions;
		p_lower_row[i] = p4*x*y+p3*(1-x)*y+p2*x*(1-y)+p1*(1-x)*(1-y);

		// and now set the normal vector
		dndx = p4*y-p3*y+p2*(1-y)-p1*(1-y);
		dndy = p4*x-p2*x+p3*(1-x)-p1*(1-x);
		n_lower_row[i] = fem::cross_product(dndx, dndy);
	}

	// the rest of the loop
	for (int j = 1; j <= partitions; j++)  
	{ 
		y = (double)j/partitions;
		// and now let's render
		glBegin(GL_TRIANGLE_STRIP);  
		for (int i = 0; i <= partitions; i++)  
		{ 
			// get the upper row points and normal vectors
			x = (double)i/partitions;
			pu[i] = p4*x*y+p3*(1-x)*y+p2*x*(1-y)+p1*(1-x)*(1-y);

			// and now set the normal vector
			dndx = p4*y-p3*y+p2*(1-y)-p1*(1-y);
			dndy = p4*x-p2*x+p3*(1-x)-p1*(1-x);

			nu[i] = fem::cross_product(dndx, dndy);

			// draw the triangles
			glNormal3dv(nu[i].data);
			glVertex3dv(pu[i].data);
			glNormal3dv(nl[i].data);
			glVertex3dv(pl[i].data);
		} 
		// swap buffer pointes
		pl = pu;
		pu = (pu == p_upper_row)?p_lower_row:p_upper_row;
		nl = nu;
		nu = (nu == n_upper_row)?n_lower_row:n_upper_row;

		glEnd(); 
	} 
}


inline void GLWidget::renderQuad9(const fem::point &p1, const fem::point &p2, const fem::point &p3, const fem::point &p4,const fem::point &p5, const fem::point &p6, const fem::point &p7, const fem::point &p8, const fem::point &p9, int partitions)
{
	// defining temporary structures for points and normal vectors
	fem::point p_upper_row[partitions+1];
	fem::point *pu;
	fem::point n_upper_row[partitions+1];
	fem::point *nu;
	fem::point p_lower_row[partitions+1];
	fem::point *pl;
	fem::point n_lower_row[partitions+1];
	fem::point *nl;

	float x, y;
	fem::point dndx;
	fem::point dndy;

	// position the pointers
	pu = p_upper_row;
	pl = p_lower_row;

	nu = n_upper_row;
	nl = n_lower_row;

	// initialize the bottom row
	y = 0;
	for(int i = 0; i <= partitions; i++)
	{
		x = ((double)i)/partitions;
		p_lower_row[i] = 16.0*p5*(1-x)*x*(1-y)*y - 8.0*p6*(0.5-x)*x*(1-y)*y + 8.0*p4*(0.5-x)*(1-x)*(1-y)*y - 8.0*p8*(1-x)*x*(0.5-y)*y + 4.0*p9*(0.5-x)*x*(0.5-y)*y - 4.0*p7*(0.5-x)*(1-x)*(0.5-y)*y + 8.0*p2*(1-x)*x*(0.5-y)*(1-y) - 4.0*p3*(0.5-x)*x*(0.5-y)*(1-y) + 4.0*p1*(0.5-x)*(1-x)*(0.5-y)*(1-y);

		// and now set the normal vector
		dndx = 8.0*p6*x*(1-y)*y-16.0*p5*x*(1-y)*y+16.0*p5*(1-x)*(1-y)*y-8.0*p4*(1-x)*(1-y)*y-8.0*p6*(0.5-x)*(1-y)*y-8.0*p4*(0.5-x)*(1-y)*y-4.0*p9*x*(0.5-y)*y+8.0*p8*x*(0.5-y)*y-8.0*p8*(1-x)*(0.5-y)*y +4.0*p7*(1-x)*(0.5-y)*y+4.0*p9*(0.5-x)*(0.5-y)*y+4.0*p7*(0.5-x)*(0.5-y)*y+4.0*p3*x*(0.5-y)*(1-y)-8.0*p2*x*(0.5-y)*(1-y)+8.0*p2*(1-x)*(0.5-y)*(1-y)-4.0*p1*(1-x)*(0.5-y)*(1-y) -4.0*p3*(0.5-x)*(0.5-y)*(1-y)-4.0*p1*(0.5-x)*(0.5-y)*(1-y);
		dndy = 8.0*p8*(1-x)*x*y-16.0*p5*(1-x)*x*y-4.0*p9*(0.5-x)*x*y+8.0*p6*(0.5-x)*x*y+4.0*p7*(0.5-x)*(1-x)*y-8.0*p4*(0.5-x)*(1-x)*y+16.0*p5*(1-x)*x*(1-y)-8.0*p2*(1-x)*x*(1-y)-8.0*p6*(0.5-x)*x*(1-y) +4.0*p3*(0.5-x)*x*(1-y)+8.0*p4*(0.5-x)*(1-x)*(1-y)-4.0*p1*(0.5-x)*(1-x)*(1-y)-8.0*p8*(1-x)*x*(0.5-y)-8.0*p2*(1-x)*x*(0.5-y)+4.0*p9*(0.5-x)*x*(0.5-y)+4.0*p3*(0.5-x)*x*(0.5-y) -4.0*p7*(0.5-x)*(1-x)*(0.5-y)-4.0*p1*(0.5-x)*(1-x)*(0.5-y);
		n_lower_row[i] = fem::cross_product(dndx, dndy);
	}

	// the rest of the loop
	for (int j = 1; j <= partitions; j++)  
	{ 
		y = (double)j/partitions;
		// and now let's render
		glBegin(GL_TRIANGLE_STRIP);  
		for (int i = 0; i <= partitions; i++)  
		{ 
			// get the upper row points and normal vectors
			x = (double)i/partitions;
			pu[i] = 16.0*p5*(1-x)*x*(1-y)*y - 8.0*p6*(0.5-x)*x*(1-y)*y + 8.0*p4*(0.5-x)*(1-x)*(1-y)*y - 8.0*p8*(1-x)*x*(0.5-y)*y + 4.0*p9*(0.5-x)*x*(0.5-y)*y - 4.0*p7*(0.5-x)*(1-x)*(0.5-y)*y + 8.0*p2*(1-x)*x*(0.5-y)*(1-y) - 4.0*p3*(0.5-x)*x*(0.5-y)*(1-y) + 4.0*p1*(0.5-x)*(1-x)*(0.5-y)*(1-y);

			// and now set the normal vector for the upper row
			dndx = 8.0*p6*x*(1-y)*y-16.0*p5*x*(1-y)*y+16.0*p5*(1-x)*(1-y)*y-8.0*p4*(1-x)*(1-y)*y-8.0*p6*(0.5-x)*(1-y)*y-8.0*p4*(0.5-x)*(1-y)*y-4.0*p9*x*(0.5-y)*y+8.0*p8*x*(0.5-y)*y-8.0*p8*(1-x)*(0.5-y)*y +4.0*p7*(1-x)*(0.5-y)*y+4.0*p9*(0.5-x)*(0.5-y)*y+4.0*p7*(0.5-x)*(0.5-y)*y+4.0*p3*x*(0.5-y)*(1-y)-8.0*p2*x*(0.5-y)*(1-y)+8.0*p2*(1-x)*(0.5-y)*(1-y)-4.0*p1*(1-x)*(0.5-y)*(1-y) -4.0*p3*(0.5-x)*(0.5-y)*(1-y)-4.0*p1*(0.5-x)*(0.5-y)*(1-y);
			dndy = 8.0*p8*(1-x)*x*y-16.0*p5*(1-x)*x*y-4.0*p9*(0.5-x)*x*y+8.0*p6*(0.5-x)*x*y+4.0*p7*(0.5-x)*(1-x)*y-8.0*p4*(0.5-x)*(1-x)*y+16.0*p5*(1-x)*x*(1-y)-8.0*p2*(1-x)*x*(1-y)-8.0*p6*(0.5-x)*x*(1-y) +4.0*p3*(0.5-x)*x*(1-y)+8.0*p4*(0.5-x)*(1-x)*(1-y)-4.0*p1*(0.5-x)*(1-x)*(1-y)-8.0*p8*(1-x)*x*(0.5-y)-8.0*p2*(1-x)*x*(0.5-y)+4.0*p9*(0.5-x)*x*(0.5-y)+4.0*p3*(0.5-x)*x*(0.5-y) -4.0*p7*(0.5-x)*(1-x)*(0.5-y)-4.0*p1*(0.5-x)*(1-x)*(0.5-y);
			nu[i] = fem::cross_product(dndx, dndy);

			// draw the triangles
			glNormal3dv(nu[i].data);
			glVertex3dv(pu[i].data);
			glNormal3dv(nl[i].data);
			glVertex3dv(pl[i].data);
		} 
		// swap buffer pointes
		pl = pu;
		pu = (pu == p_upper_row)?p_lower_row:p_upper_row;

		nl = nu;
		nu = (nu == n_upper_row)?n_lower_row:n_upper_row;
		glEnd(); 
	} 
}


inline void GLWidget::renderTriangle3(const fem::point &p1, const fem::point &p2, const fem::point &p3, int partitions)
{
	partitions = 1;	// just to shut up the warning
	fem::point temp;
	temp = getNormalVector(p1,p2,p3);
	glBegin(GL_TRIANGLES);
	glNormal3dv(temp.data);
	glVertex3dv(p1.data);
	glVertex3dv(p2.data);
	glVertex3dv(p3.data);
	glEnd();
}


inline void GLWidget::renderTriangle6(const fem::point &p1, const fem::point &p2,const fem::point &p3,const fem::point &p4, const fem::point &p5, const fem::point &p6, int partitions)
{
	// defining temporary structures for points and normal vectors
	fem::point p_upper_row[partitions+1];
	fem::point *pu;
	fem::point n_upper_row[partitions+1];
	fem::point *nu;
	fem::point p_lower_row[partitions+1];
	fem::point *pl;
	fem::point n_lower_row[partitions+1];
	fem::point *nl;

	float x, y;
	fem::point dndx;
	fem::point dndy;

	// position the pointers
	pu = p_upper_row;
	pl = p_lower_row;

	nu = n_upper_row;
	nl = n_lower_row;

	// initialize the bottom row
	y = 0;
	for(int i = 0; i <= partitions; i++)
	{
		x = ((double)i)/partitions;
		p_lower_row[i] = p3*y*(2*y-1)+4*p6*(-y-x+1)*y+4*p5*x*y+p1*(2*(-y-x+1)-1)*(-y-x+1)+4*p4*x*(-y-x+1)+p2*x*(2*x-1);

		// and now set the normal vector
		dndx = -4*p6*y+4*p5*y+4*p4*(-y-x+1)-2*p1*(-y-x+1)-p1*(2*(-y-x+1)-1)+p2*(2*x-1)-4*p4*x+2*p2*x;
		dndy = p3*(2*y-1)-4*p6*y+2*p3*y+4*p6*(-y-x+1)-2*p1*(-y-x+1)-p1*(2*(-y-x+1)-1)+4*p5*x-4*p4*x;
		
		n_lower_row[i] = fem::cross_product(dndx, dndy);
	}

	// the rest of the loop
	for (int j = 1, i; j <= partitions; j++)  
	{ 
		y = (double)j/partitions;
		// and now let's render
		glBegin(GL_TRIANGLE_STRIP);  
		for (i = 0; i <= (partitions-j); i++)  
		{ 
			// get the upper row points and normal vectors
			x = (double)i/partitions;
			pu[i] = p3*y*(2*y-1)+4*p6*(-y-x+1)*y+4*p5*x*y+p1*(2*(-y-x+1)-1)*(-y-x+1)+4*p4*x*(-y-x+1)+p2*x*(2*x-1);

			// and now set the normal vector for the upper row
			dndx = -4*p6*y+4*p5*y+4*p4*(-y-x+1)-2*p1*(-y-x+1)-p1*(2*(-y-x+1)-1)+p2*(2*x-1)-4*p4*x+2*p2*x;
			dndy = p3*(2*y-1)-4*p6*y+2*p3*y+4*p6*(-y-x+1)-2*p1*(-y-x+1)-p1*(2*(-y-x+1)-1)+4*p5*x-4*p4*x;
			nu[i] = fem::cross_product(dndx, dndy);

			// draw the triangles
			glNormal3dv(nu[i].data);
			glVertex3dv(pu[i].data);
			glNormal3dv(nl[i].data);
			glVertex3dv(pl[i].data);
		} 
		glNormal3dv(nl[i].data);
		glVertex3dv(pl[i].data);
		glEnd(); 

		// swap buffer pointes
		pl = pu;
		pu = (pu == p_upper_row)?p_lower_row:p_upper_row;

		nl = nu;
		nu = (nu == n_upper_row)?n_lower_row:n_upper_row;
	} 
}


void GLWidget::generateDisplayLists()
{
	// generate nodes display list
	generateNodesDisplayList();

	// the faces
	glNewList( dl_faces, GL_COMPILE);
	std::vector<fem::Element>::iterator ei;	// element iterator
	for(ei = document->model.element_list.begin(); ei != document->model.element_list.end(); ei++)
	{
		paintElement(*ei);
	}
	glEndList();


	// and now the wireframe
	glNewList( dl_wireframe, GL_COMPILE);
	for(ei = document->model.element_list.begin(); ei != document->model.element_list.end(); ei++)
	{
		paintWireframe(*ei);
	}
	glEndList();
}


void GLWidget::generateNodesDisplayList()
{
	glNewList( dl_nodes, GL_COMPILE);
	std::map<size_t,fem::Node>::iterator ni;	// node iterator
	for(ni = document->model.node_list.begin(); ni != document->model.node_list.end(); ni++)
	{
		paintNode(ni->first, ni->second);
	}
	glEndList();
}


void GLWidget::mousePressEvent(QMouseEvent *event)
{
	lastPos = event->pos();

	// process left clicks
	if(event->buttons() & Qt::LeftButton)
	{
		fem::point near, far;
		QPoint pos = event->pos();
		GLdouble modelview[16];
		GLdouble projection[16];
		GLint viewport[4];

		glGetDoublev(GL_MODELVIEW_MATRIX, modelview);
		glGetDoublev(GL_PROJECTION_MATRIX, projection);
		glGetIntegerv(GL_VIEWPORT, viewport);
		gluUnProject(pos.x(), viewport[3]-pos.y(), 0, modelview, projection, viewport, &near.data[0], &near.data[1], &near.data[2]);
		gluUnProject(pos.x(), viewport[3]-pos.y(), 1, modelview, projection, viewport, &far.data[0], &far.data[1], &far.data[2]);

		// push the line
		selectModelObjects(near, far);
		generateNodesDisplayList();
		updateGL();
	}
}


void GLWidget::mouseMoveEvent(QMouseEvent *event)
{
	int dx = event->x() - lastPos.x();
	int dy = event->y() - lastPos.y();

	if (event->buttons() & Qt::LeftButton) {
		//TODO set action for left click button
	} else if (event->buttons() & Qt::RightButton) {
		setXRotation(camera.rotation.data[0] + dy);
		setYRotation(camera.rotation.data[1] + dx);
	}
	else if (event->buttons() & Qt::MidButton) {
		// setPosition(camera.pos.data[0] + dx, camera.pos.data[1] + dy);
	}
	lastPos = event->pos();
}


void GLWidget::wheelEvent(QWheelEvent *event)
{
	//camera.pos.inc_x(event->delta()/800.0f);
	zoom += event->delta()/1000.0f;
	qWarning("zoom: %f, %f",zoom, pow(2,zoom));
	this->resizeGL(this->width(), this->height());
	this->updateGL();
	event->accept();
}


void GLWidget::keyPressEvent(QKeyEvent *event)
{
	switch( event->key() )
	{
		case Qt::Key_Escape:
			document->model_selection.deselectAll();
			generateNodesDisplayList();
			updateGL();
			break;

		default:
			break;
	}
}


void GLWidget::normalizeAngle(int *angle)
{
	while (*angle < 0)
		*angle += 360 * 16;
	while (*angle > 360 * 16)
		*angle -= 360 * 16;
}


void GLWidget::paintNode(size_t label, const fem::Node node)
{
	glPushMatrix();
	glTranslated(node.data[0],node.data[1],node.data[2]);
	
	glScalef(node_scale/aspect_ratio, node_scale/aspect_ratio, node_scale/aspect_ratio);

	//TODO find a better rendering for the nodes
	glBegin(GL_LINES);
		glColor3f(1.0f,0.0f,0.0f);
		glVertex3i(0,0,0);
		glVertex3i(2,0,0);
		glColor3f(0.0f,1.0f,0.0f);
		glVertex3i(0,0,0);
		glVertex3i(0,2,0);
		glColor3f(0.0f,0.0f,1.0f);
		glVertex3i(0,0,0);
		glVertex3i(0,0,2);
	glEnd();

	// paint the nodal sphere
	//if(document->selected_nodes[label])
	if(document->model_selection.isNodeSelected(label))
		glColor3f(1.0f,0,0);
	else
		glColor3fv(colors->node);
	GLUquadric *p;
	p = gluNewQuadric();
	gluSphere(p,1,8,8);

	// paint restrictions, if there are any
	if(document->model.node_restrictions_list.find(label) != document->model.node_restrictions_list.end())
	{
		if(document->model.node_restrictions_list[label].dx())
		{
			glBegin(GL_TRIANGLES);
			glNormal3f(1.4142f, 0, 1.4142f);
			glVertex3i(0,0,0);
			glVertex3i(-2,2,2);
			glVertex3i(-2,-2,2);

			glNormal3f(1.4142f,-1.4142f, 0);
			glVertex3i(0,0,0);
			glVertex3i(-2,-2, 2);
			glVertex3i(-2,-2,-2);

			glNormal3f(1.4142f, 0, -1.4142f);
			glVertex3i(0,0,0);
			glVertex3i(-2,-2,-2);
			glVertex3i(-2, 2,-2);

			glNormal3f(1.4142f, 1.4142f, 0);
			glVertex3i(0,0,0);
			glVertex3i(-2, 2,-2);
			glVertex3i(-2, 2, 2);

			// backface
			glNormal3f(-1,0,0);
			glVertex3i(-2, 2, 2);
			glVertex3i(-2, 2,-2);
			glVertex3i(-2,-2,-2);
			glVertex3i(-2,-2,-2);
			glVertex3i(-2,-2, 2);
			glVertex3i(-2, 2, 2);
			glEnd();
		}
		if(document->model.node_restrictions_list[label].dy())
		{
			// render the pyramid
			glBegin(GL_TRIANGLES);
			glNormal3i( 2, 0, 2);
			glVertex3i( 0, 0, 0);
			glVertex3i( 2,-2,-2);
			glVertex3i( 2, 2,-2);

			glNormal3i( 0,-2, 2);
			glVertex3i(0,0,0);
			glVertex3i(-2,-2,-2);
			glVertex3i( 2,-2,-2);

			glNormal3i(-2, 0, 2);
			glVertex3i(0,0,0);
			glVertex3i(-2, 2,-2);
			glVertex3i(-2,-2,-2);

			glNormal3i( 0, 2, 2);
			glVertex3i(0,0,0);
			glVertex3i( 2, 2,-2);
			glVertex3i(-2, 2,-2);

			// backface
			glNormal3f( 0,0,-1);
			glVertex3i( 2, 2,-2);
			glVertex3i(-2,-2,-2);
			glVertex3i(-2, 2,-2);
			glVertex3i(-2,-2,-2);
			glVertex3i( 2, 2,-2);
			glVertex3i( 2,-2,-2);
			glEnd();
		}
		if(document->model.node_restrictions_list[label].dz())
		{
			glRotatef(-90,1,0,0);
			// render the pyramid
			glBegin(GL_TRIANGLES);
			glNormal3i( 2, 0, 2);
			glVertex3i( 0, 0, 0);
			glVertex3i( 2,-2,-2);
			glVertex3i( 2, 2,-2);

			glNormal3i( 0,-2, 2);
			glVertex3i(0,0,0);
			glVertex3i(-2,-2,-2);
			glVertex3i( 2,-2,-2);

			glNormal3i(-2, 0, 2);
			glVertex3i(0,0,0);
			glVertex3i(-2, 2,-2);
			glVertex3i(-2,-2,-2);

			glNormal3i( 0, 2, 2);
			glVertex3i(0,0,0);
			glVertex3i( 2, 2,-2);
			glVertex3i(-2, 2,-2);

			// backface
			glNormal3f( 0,0,-1);
			glVertex3i( 2, 2,-2);
			glVertex3i(-2,-2,-2);
			glVertex3i(-2, 2,-2);
			glVertex3i(-2,-2,-2);
			glVertex3i( 2, 2,-2);
			glVertex3i( 2,-2,-2);
			glEnd();
		}
	}

	// end 
	glPopMatrix();
}


void GLWidget::paintElement(const fem::Element &element)
{
	std::map<size_t, fem::Node>::iterator n;
	std::vector<fem::point> nl;	// node list
	fem::point p;
	glPushMatrix();
	switch(element.type)
	{
		case fem::Element::FE_TETRAHEDRON4:
			{
				// set the node list
				nl.push_back(document->model.node_list.find(element.nodes[0])->second);
				nl.push_back(document->model.node_list.find(element.nodes[1])->second);
				nl.push_back(document->model.node_list.find(element.nodes[2])->second);
				nl.push_back(document->model.node_list.find(element.nodes[3])->second);

				// render the surfaces
				// set the color
				glColor3fv(colors->tetrahedron4);

				if(element.nodes.size() != 4)
				{
					qWarning("error: invalid number of nodes for a FE_TETRAHEDRON4. it's %zd", element.nodes.size());
					//TODO remove element?
					return;
				}

				renderTriangle3(nl[0], nl[2], nl[1]);
				renderTriangle3(nl[0], nl[1], nl[3]);
				renderTriangle3(nl[1], nl[2], nl[3]);
				renderTriangle3(nl[2], nl[0], nl[3]);
			}
			break;

		case fem::Element::FE_TETRAHEDRON10:
			{
				// set the node list
				nl.push_back(document->model.node_list.find(element.nodes[0])->second);
				nl.push_back(document->model.node_list.find(element.nodes[1])->second);
				nl.push_back(document->model.node_list.find(element.nodes[2])->second);
				nl.push_back(document->model.node_list.find(element.nodes[3])->second);
				nl.push_back(document->model.node_list.find(element.nodes[4])->second);
				nl.push_back(document->model.node_list.find(element.nodes[5])->second);
				nl.push_back(document->model.node_list.find(element.nodes[6])->second);
				nl.push_back(document->model.node_list.find(element.nodes[7])->second);
				nl.push_back(document->model.node_list.find(element.nodes[8])->second);
				nl.push_back(document->model.node_list.find(element.nodes[9])->second);

				// render the surfaces
				// set the color
				glColor3fv(colors->tetrahedron4);

				if(element.nodes.size() != 10)
				{
					qWarning("error: invalid number of nodes for a FE_TETRAHEDRON10. it's %zd", element.nodes.size());
					//TODO remove element
					return;
				}

				renderTriangle6(nl[0], nl[3], nl[2], nl[7], nl[8], nl[6]);
				renderTriangle6(nl[3], nl[1], nl[2], nl[9], nl[5], nl[8]);
				renderTriangle6(nl[1], nl[0], nl[2], nl[4], nl[6], nl[5]);
				renderTriangle6(nl[0], nl[1], nl[3], nl[4], nl[9], nl[7]);
			}
			break;

		case fem::Element::FE_HEXAHEDRON8:
			{
				//GLfloat mapsurface[12];	// for the mapsurface
				if(element.nodes.size() != 8)
				{
					qWarning("error: invalid number of nodes for a FE_HEXAHEDRON8");
					//TODO remove element
					return;
				}
				nl.push_back(document->model.node_list.find(element.nodes[0])->second);
				nl.push_back(document->model.node_list.find(element.nodes[1])->second);
				nl.push_back(document->model.node_list.find(element.nodes[2])->second);
				nl.push_back(document->model.node_list.find(element.nodes[3])->second);
				nl.push_back(document->model.node_list.find(element.nodes[4])->second);
				nl.push_back(document->model.node_list.find(element.nodes[5])->second);
				nl.push_back(document->model.node_list.find(element.nodes[6])->second);
				nl.push_back(document->model.node_list.find(element.nodes[7])->second);
				// set the color
				glColor3fv(colors->hexahedron8);

				// render the hexahedron's 6 surfaces
				renderQuad4(nl[1], nl[0], nl[2], nl[3]);
				renderQuad4(nl[5], nl[1], nl[6], nl[2]);
				renderQuad4(nl[4], nl[5], nl[7], nl[6]);
				renderQuad4(nl[0], nl[4], nl[3], nl[7]);
				renderQuad4(nl[7], nl[6], nl[3], nl[2]);
				renderQuad4(nl[0], nl[1], nl[4], nl[5]);
			}
			break;

		case fem::Element::FE_HEXAHEDRON27:
			{
				//GLfloat mapsurface[12];	// for the mapsurface
				if(element.nodes.size() != 27)
				{
					qWarning("error: invalid number of nodes for a FE_HEXAHEDRON27");
					//TODO remove element
					return;
				}

				// build the node temp list
				for(int i = 0; i < 27; i++)
				{
					nl.push_back(document->model.node_list.find(element.nodes[i])->second);
				}

				// set the color
				glColor3fv(colors->hexahedron8);

				renderQuad9(nl[1],nl[8],nl[0],nl[11],nl[20],nl[9],nl[2],nl[13],nl[3]);
				renderQuad9(nl[0],nl[10],nl[4],nl[9],nl[22],nl[17],nl[3],nl[15],nl[7]);
				renderQuad9(nl[4],nl[16],nl[5],nl[17],nl[25],nl[18],nl[7],nl[19],nl[6]);
				renderQuad9(nl[5],nl[12],nl[1],nl[18],nl[23],nl[11],nl[6],nl[14],nl[2]);
				renderQuad9(nl[7],nl[19],nl[6],nl[15],nl[24],nl[14],nl[3],nl[13],nl[2]);
				renderQuad9(nl[5],nl[16],nl[4],nl[12],nl[21],nl[10],nl[1],nl[8],nl[0]);
			}
			break;

		case fem::Element::FE_PRISM6:
			{
				// set the node list
				nl.push_back(document->model.node_list.find(element.nodes[0])->second);
				nl.push_back(document->model.node_list.find(element.nodes[1])->second);
				nl.push_back(document->model.node_list.find(element.nodes[2])->second);
				nl.push_back(document->model.node_list.find(element.nodes[3])->second);
				nl.push_back(document->model.node_list.find(element.nodes[4])->second);
				nl.push_back(document->model.node_list.find(element.nodes[5])->second);

				// render the surfaces
				// set the color
				glColor3fv(colors->prism6);

				if(element.nodes.size() != 6)
				{
					qWarning("error: invalid number of nodes for a FE_PRISM6. it's %zd", element.nodes.size());
					//TODO remove element
					return;
				}

				//TODO check surface orientation
				renderTriangle3(nl[2], nl[1], nl[0]);
				renderTriangle3(nl[4], nl[5], nl[3]);
				renderQuad4(nl[3], nl[0], nl[4], nl[1]);
				renderQuad4(nl[5], nl[2], nl[3], nl[0]);
				renderQuad4(nl[4], nl[1], nl[5], nl[2]);
			}
			break;

		default:
			//qWarning("error: unknown element type: %d", element.type);
			break;
	}
	glPopMatrix();
}


void GLWidget::paintWireframe(const fem::Element &element)
{
	std::map<size_t, fem::Node>::iterator n;
	std::vector<fem::point> nl;	// node list
	fem::point p;
	glDisable(GL_LIGHTING); 
	glPushMatrix();

	switch(element.type)
	{
		case fem::Element::FE_TETRAHEDRON4:
			{
				// set the node list
				nl.push_back(document->model.node_list.find(element.nodes[0])->second);
				nl.push_back(document->model.node_list.find(element.nodes[1])->second);
				nl.push_back(document->model.node_list.find(element.nodes[2])->second);
				nl.push_back(document->model.node_list.find(element.nodes[3])->second);
				// render the wireframe
				//TODO set color
				glColor3fv(colors->wireframe);	
				glBegin(GL_LINE_STRIP);
				glVertex3dv(nl[0].data);
				glVertex3dv(nl[1].data);
				glVertex3dv(nl[2].data);
				glVertex3dv(nl[0].data);
				glVertex3dv(nl[3].data);
				glVertex3dv(nl[1].data);
				glEnd();
				glBegin(GL_LINES);
				glVertex3dv(nl[3].data);
				glVertex3dv(nl[2].data);
				glEnd();
			}
			break;

		case fem::Element::FE_TETRAHEDRON10:
			{
				// set the node list
				nl.push_back(document->model.node_list.find(element.nodes[0])->second);
				nl.push_back(document->model.node_list.find(element.nodes[1])->second);
				nl.push_back(document->model.node_list.find(element.nodes[2])->second);
				nl.push_back(document->model.node_list.find(element.nodes[3])->second);
				nl.push_back(document->model.node_list.find(element.nodes[4])->second);
				nl.push_back(document->model.node_list.find(element.nodes[5])->second);
				nl.push_back(document->model.node_list.find(element.nodes[6])->second);
				nl.push_back(document->model.node_list.find(element.nodes[7])->second);
				nl.push_back(document->model.node_list.find(element.nodes[8])->second);
				nl.push_back(document->model.node_list.find(element.nodes[9])->second);


				// render the wireframe
				//TODO set color
				glColor3fv(colors->wireframe);	

				renderLine3(nl[0], nl[7], nl[3]);
				renderLine3(nl[3], nl[9], nl[1]);
				renderLine3(nl[1], nl[4], nl[0]);
				renderLine3(nl[0], nl[6], nl[2]);
				renderLine3(nl[2], nl[5], nl[1]);
				renderLine3(nl[2], nl[8], nl[3]);
			}
			break;

		case fem::Element::FE_HEXAHEDRON8:
			{
				//GLfloat mapsurface[12];	// for the mapsurface
				if(element.nodes.size() != 8)
				{
					qWarning("error: invalid number of nodes for a FE_HEXAHEDRON8");
					//TODO remove element
					return;
				}
				nl.push_back(document->model.node_list.find(element.nodes[0])->second);
				nl.push_back(document->model.node_list.find(element.nodes[1])->second);
				nl.push_back(document->model.node_list.find(element.nodes[2])->second);
				nl.push_back(document->model.node_list.find(element.nodes[3])->second);
				nl.push_back(document->model.node_list.find(element.nodes[4])->second);
				nl.push_back(document->model.node_list.find(element.nodes[5])->second);
				nl.push_back(document->model.node_list.find(element.nodes[6])->second);
				nl.push_back(document->model.node_list.find(element.nodes[7])->second);
				// set the color
				glColor3fv(colors->wireframe);	// TODO change this

				glBegin(GL_LINE_STRIP);
				glVertex3dv(nl[0].data);
				glVertex3dv(nl[1].data);
				glVertex3dv(nl[2].data);
				glVertex3dv(nl[3].data);
				glVertex3dv(nl[0].data);

				glVertex3dv(nl[4].data);
				glVertex3dv(nl[5].data);
				glVertex3dv(nl[6].data);
				glVertex3dv(nl[7].data);
				glVertex3dv(nl[4].data);
				glEnd();

				glBegin(GL_LINES);
				glVertex3dv(nl[1].data);
				glVertex3dv(nl[5].data);
				glVertex3dv(nl[2].data);
				glVertex3dv(nl[6].data);
				glVertex3dv(nl[3].data);
				glVertex3dv(nl[7].data);
				glEnd();
			}
			break;

		case fem::Element::FE_HEXAHEDRON27:
			{
				//GLfloat mapsurface[12];	// for the mapsurface
				if(element.nodes.size() != 27)
				{
					qWarning("error: invalid number of nodes for a FE_HEXAHEDRON27");
					//TODO remove element
					return;
				}

				// build the node temp list
				for(int i = 0; i < 27; i++)
				{
					nl.push_back(document->model.node_list.find(element.nodes[i])->second);
				}

				// set the color
				glColor3fv(colors->wireframe);

				//TODO make this an option
				//int subdiv = 10;	

				renderLine3(nl[0],nl[8],nl[1]);
				renderLine3(nl[1], nl[11], nl[2]);
				renderLine3(nl[2], nl[13], nl[3]);
				renderLine3(nl[3], nl[9], nl[0]);

				renderLine3(nl[4], nl[16], nl[5]);
				renderLine3(nl[5], nl[18], nl[6]);
				renderLine3(nl[6], nl[19], nl[7]);
				renderLine3(nl[7], nl[17], nl[4]);

				renderLine3(nl[0], nl[10], nl[4]);
				renderLine3(nl[3], nl[15], nl[7]);
				renderLine3(nl[2], nl[14], nl[6]);
				renderLine3(nl[1], nl[12], nl[5]);
			}
			break;

		case fem::Element::FE_PRISM6:
			{
				// set the node list
				nl.push_back(document->model.node_list.find(element.nodes[0])->second);
				nl.push_back(document->model.node_list.find(element.nodes[1])->second);
				nl.push_back(document->model.node_list.find(element.nodes[2])->second);
				nl.push_back(document->model.node_list.find(element.nodes[3])->second);
				nl.push_back(document->model.node_list.find(element.nodes[4])->second);
				nl.push_back(document->model.node_list.find(element.nodes[5])->second);

				// render the wireframe
				//TODO set color
				glColor3fv(colors->wireframe);	

				//TODO set wireframe
				/*
				   renderLine3(nl[0], nl[7], nl[3]);
				   renderLine3(nl[3], nl[9], nl[1]);
				   renderLine3(nl[1], nl[4], nl[0]);
				   renderLine3(nl[0], nl[6], nl[2]);
				   renderLine3(nl[2], nl[5], nl[1]);
				   renderLine3(nl[2], nl[8], nl[3]);
				 */
			}
			break;

		default:
			//qWarning("error: unknown element type: %d", element.type);
			break;
	}
	glPopMatrix();
	glEnable(GL_LIGHTING);
}


void GLWidget::selectModelObjects(const fem::point &near,const fem::point &far)
{
	// test nodes
	float a, b, c;
	float x2x1, y2y1, z2z1; // helper temp variables to avoid remultiplying
	std::map<size_t,float> distance_map;

	// get 
	for(std::map<size_t,fem::Node>::iterator i = document->model.node_list.begin(); i != document->model.node_list.end(); i++)
	{
		x2x1 = far.data[0]-near.data[0];
		y2y1 = far.data[1]-near.data[1];
		z2z1 = far.data[2]-near.data[2];
		a = x2x1*x2x1 + y2y1*y2y1 + z2z1*z2z1;
		b = 2*(x2x1*(near.data[0]-i->second.data[0]) + y2y1*(near.data[1] - i->second.data[1]) + z2z1*(near.data[2]-i->second.data[2]));
		c = i->second.data[0]*i->second.data[0] + i->second.data[1]*i->second.data[1] + i->second.data[2]*i->second.data[2] + near.data[0]*near.data[0]+ near.data[1]*near.data[1] + near.data[2]*near.data[2] - 2*(i->second.data[0]*near.data[0]+i->second.data[1]*near.data[1]+i->second.data[2]*near.data[2]) - node_scale*node_scale/(aspect_ratio*aspect_ratio);
		if(b*b - 4*a*c > 0)
		{
			//distance_map[i->first] = (i->second-near).norm(); // get distances
			document->model_selection.selectNode(i->first);
		}
	}
	// select the nearest hit
	// document->selectNode(std::min_element(distance_map.begin(), distance_map.end(), distance_map.value_comp())->first);
}
