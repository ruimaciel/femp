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
	makeCurrent();

	// initialize the camera
	camera.reset();
	camera.setCenter(0,0,-5);

	//TODO set state from program option

	setNodeRadiusScale(20);	// default node radius, scaled
	
	// initialize the dangling pointers
	document = NULL;
	colors = NULL;

	qtPurple = QColor::fromCmykF(0.39, 0.39, 0.0, 0.0);

	// starts off with perspective
	perspective = true;
}


GLWidget::~GLWidget()
{
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


void GLWidget::togglePerspective()
{
	perspective = (perspective?false:true);
	this->resizeGL(this->width(), this->height());
	updateGL();
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
			std::map<size_t,fem::Node>::iterator ni;	// node iterator
			for(ni = document->model.node_list.begin(); ni != document->model.node_list.end(); ni++)
			{
				paintNode(ni->first, ni->second);
			}
		}

		// render all elements
		std::vector<fem::Element>::iterator ei;	// element iterator
		for(ei = document->model.element_list.begin(); ei != document->model.element_list.end(); ei++)
		{
			paintElement(*ei);
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
	scale = qMin(width, height);
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	
	if(perspective)
		gluPerspective(45.0, (float)width/(float)height, 0.1, 1000);
	else
		glOrtho(-(width*2)/(scale), (width*2)/(scale), -height*2/(scale), +height*2/(scale), 0.1, 1000.0);
	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
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
	camera.pos.inc_x(event->delta()/800.0f);
	updateGL();
	event->accept();
}


void GLWidget::keyPressEvent(QKeyEvent *event)
{
	switch( event->key() )
	{
		case Qt::Key_Escape:
			document->deselectAll();
			updateGL();
			break;

		case Qt::Key_P:
			togglePerspective();
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
	
	glScalef(node_scale/scale, node_scale/scale, node_scale/scale);

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
	if(document->selected_nodes[label])
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
		/*
		case fem::Element::FE_LINE2:
			{
				if(element.nodes.size() != 2)
				{
					qWarning("error: invalid number of nodes for a FE_LINE2");
					//TODO remove element
					return;
				}
				nl.push_back(document->model.node_list.find(element.nodes[0])->second);
				nl.push_back(document->model.node_list.find(element.nodes[1])->second);
				glBegin(GL_LINES);
				glVertex3dv(nl[0].data);
				glVertex3dv(nl[1].data);
				glEnd();
			}
			break;

		case fem::Element::FE_TRIANGLE3:
			{
				if(element.nodes.size() != 3)
				{
					qWarning("error: invalid number of nodes for a FE_TRIANGLE3");
					//TODO remove element
					return;
				}
				nl.push_back(document->model.node_list.find(element.nodes[0])->second);
				nl.push_back(document->model.node_list.find(element.nodes[1])->second);
				nl.push_back(document->model.node_list.find(element.nodes[2])->second);
				glBegin(GL_LINE_STRIP);
				glVertex3dv(nl[0].data);
				glVertex3dv(nl[1].data);
				glVertex3dv(nl[2].data);
				glVertex3dv(nl[0].data);
				glEnd();
			}
			break;
			*/

		case fem::Element::FE_TETRAHEDRON4:
			{
				// set the node list
				nl.push_back(document->model.node_list.find(element.nodes[0])->second);
				nl.push_back(document->model.node_list.find(element.nodes[1])->second);
				nl.push_back(document->model.node_list.find(element.nodes[2])->second);
				nl.push_back(document->model.node_list.find(element.nodes[3])->second);

				// render the surfaces
				if(display_options.surfaces == 1)
				{
					// set the color
					glColor3fv(colors->tetrahedron4);

					if(element.nodes.size() != 4)
					{
						qWarning("error: invalid number of nodes for a FE_TETRAHEDRON4. it's %zd", element.nodes.size());
						//TODO remove element
						return;
					}
					glBegin(GL_TRIANGLES);
					glNormal3dv(fem::getNormalVector(nl[0], nl[2], nl[1]).data);
					glVertex3dv(nl[0].data);
					glVertex3dv(nl[2].data);
					glVertex3dv(nl[1].data);

					glNormal3dv(fem::getNormalVector(nl[0], nl[1], nl[3]).data);
					glVertex3dv(nl[0].data);
					glVertex3dv(nl[1].data);
					glVertex3dv(nl[3].data);

					glNormal3dv(fem::getNormalVector(nl[1], nl[2], nl[3]).data);
					glVertex3dv(nl[1].data);
					glVertex3dv(nl[2].data);
					glVertex3dv(nl[3].data);

					glNormal3dv(fem::getNormalVector(nl[2], nl[0], nl[3]).data);
					glVertex3dv(nl[2].data);
					glVertex3dv(nl[0].data);
					glVertex3dv(nl[3].data);
					glEnd();
				}

				// render the wireframe
				if(display_options.wireframe == 1)
				{
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
				if(display_options.surfaces)
				{
					// set the color
					glColor3fv(colors->hexahedron8);

					glBegin(GL_QUADS);
					// first surface
					glNormal3dv(fem::getNormalVector(nl[0], nl[3], nl[2]).data);
					glVertex3dv(nl[0].data);
					glVertex3dv(nl[3].data);
					glVertex3dv(nl[2].data);
					glVertex3dv(nl[1].data);
					// second surface
					glNormal3dv(fem::getNormalVector(nl[1], nl[2], nl[6]).data);
					glVertex3dv(nl[1].data);
					glVertex3dv(nl[2].data);
					glVertex3dv(nl[6].data);
					glVertex3dv(nl[5].data);
					// third surface
					glNormal3dv(fem::getNormalVector(nl[5], nl[6], nl[7]).data);
					glVertex3dv(nl[6].data);
					glVertex3dv(nl[7].data);
					glVertex3dv(nl[4].data);
					glVertex3dv(nl[5].data);
					// fourth surface
					glNormal3dv(fem::getNormalVector(nl[4], nl[7], nl[3]).data);
					glVertex3dv(nl[4].data);
					glVertex3dv(nl[7].data);
					glVertex3dv(nl[3].data);
					glVertex3dv(nl[0].data);
					// fifth surface, top
					glNormal3dv(fem::getNormalVector(nl[2], nl[3], nl[7]).data);
					glVertex3dv(nl[2].data);
					glVertex3dv(nl[3].data);
					glVertex3dv(nl[7].data);
					glVertex3dv(nl[6].data);
					// sixth surface, bottom
					glNormal3dv(fem::getNormalVector(nl[0], nl[1], nl[5]).data);
					glVertex3dv(nl[0].data);
					glVertex3dv(nl[1].data);
					glVertex3dv(nl[5].data);
					glVertex3dv(nl[4].data);
					glEnd();
				}

				if(display_options.wireframe)
				{
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

				if(display_options.surfaces)
				{
					// set the color
					glColor3fv(colors->hexahedron8);

					glBegin(GL_QUADS);
					//TODO render surface
					glEnd();
				}

				if(display_options.wireframe)
				{
					// set the color
					glColor3fv(colors->wireframe);

					glBegin(GL_LINE_STRIP);
					glVertex3dv(nl[0].data);
					glVertex3dv(nl[8].data);
					glVertex3dv(nl[1].data);
					glVertex3dv(nl[11].data);
					glVertex3dv(nl[2].data);
					glVertex3dv(nl[13].data);
					glVertex3dv(nl[3].data);
					glVertex3dv(nl[9].data);
					glVertex3dv(nl[0].data);

					glVertex3dv(nl[10].data);

					glVertex3dv(nl[4].data);
					glVertex3dv(nl[16].data);
					glVertex3dv(nl[5].data);
					glVertex3dv(nl[18].data);
					glVertex3dv(nl[6].data);
					glVertex3dv(nl[19].data);
					glVertex3dv(nl[7].data);
					glVertex3dv(nl[17].data);
					glVertex3dv(nl[4].data);
					glEnd();

					glBegin(GL_LINES);
					glVertex3dv(nl[1].data);
					glVertex3dv(nl[12].data);
					glVertex3dv(nl[12].data);
					glVertex3dv(nl[5].data);

					glVertex3dv(nl[2].data);
					glVertex3dv(nl[14].data);
					glVertex3dv(nl[14].data);
					glVertex3dv(nl[6].data);

					glVertex3dv(nl[3].data);
					glVertex3dv(nl[15].data);
					glVertex3dv(nl[15].data);
					glVertex3dv(nl[7].data);
					glEnd();
				}
			}
			break;

		default:
			//qWarning("error: unknown element type: %d", element.type);
			break;
	}
	glPopMatrix();
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
		c = i->second.data[0]*i->second.data[0] + i->second.data[1]*i->second.data[1] + i->second.data[2]*i->second.data[2] + near.data[0]*near.data[0]+ near.data[1]*near.data[1] + near.data[2]*near.data[2] - 2*(i->second.data[0]*near.data[0]+i->second.data[1]*near.data[1]+i->second.data[2]*near.data[2]) - node_scale*node_scale/(scale*scale);
		if(b*b - 4*a*c > 0)
		{
			//distance_map[i->first] = (i->second-near).norm(); // get distances
			document->selectNode(i->first);
		}
	}
	// select the nearest hit
	// document->selectNode(std::min_element(distance_map.begin(), distance_map.end(), distance_map.value_comp())->first);
}
