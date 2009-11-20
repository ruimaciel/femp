#include <QtGui>
#include <QtOpenGL>

#include <math.h>
#include <assert.h>
#include <map>

#include "fem/point.h++"
#include "glwidget.h++"

GLWidget::GLWidget(QWidget *parent): QGLWidget(parent)
{
	makeCurrent();
	camera.rotation.data[0] = 0;
	camera.rotation.data[1] = 0;
	camera.rotation.data[2] = 0;

	camera.pos.z(-10);
	node_scale = 0.05f;
	model = NULL;

	qtPurple = QColor::fromCmykF(0.39, 0.39, 0.0, 0.0);
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
void GLWidget::setModel(fem::Model *model)
{
	assert(model != NULL);
	this->model = model;
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


void GLWidget::setPosition(int amount)
{
	camera.pos.z(amount/100.0f);
	qWarning("pos: %f",camera.pos.z());
	updateGL();
}

void GLWidget::initializeGL()
{
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

	glTranslated(camera.pos.x(),camera.pos.y(),camera.pos.z());
	glRotated(camera.rotation.data[0], 1.0, 0.0, 0.0);
	glRotated(camera.rotation.data[1], 0.0, 1.0, 0.0);
	glRotated(camera.rotation.data[2], 0.0, 0.0, 1.0);

	// render all nodes
	if(model)
	{
		std::map<size_t,fem::Node>::iterator ni;	// node iterator
		for(ni = model->node_list.begin(); ni != model->node_list.end(); ni++)
		{
			paintNode(ni->first, ni->second);
		}

		// render all elements
		std::vector<fem::Element>::iterator ei;	// element iterator
		for(ei = model->element_list.begin(); ei != model->element_list.end(); ei++)
		{
			paintElement(*ei);
		}
	}

	/*
	// test triangle. remove after debug
	glBegin(GL_TRIANGLES);
	glNormal3f(0,0,1);
	glVertex2f(1,0);
	glVertex2f(0,1);
	glVertex2f(-1,0);
	glEnd();
	*/
}


void GLWidget::resizeGL(int width, int height)
{
	float side = qMin(width, height);
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	
	glOrtho(-(width*2)/(side), (width*2)/(side), -height*2/(side), +height*2/(side), 2.0, 100.0);
	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}


void GLWidget::mousePressEvent(QMouseEvent *event)
{
	lastPos = event->pos();
}


void GLWidget::mouseMoveEvent(QMouseEvent *event)
{
	int dx = event->x() - lastPos.x();
	int dy = event->y() - lastPos.y();

	if (event->buttons() & Qt::LeftButton) {
		setXRotation(camera.rotation.data[0] + dy);
		setYRotation(camera.rotation.data[1] + dx);
	} else if (event->buttons() & Qt::RightButton) {
		setXRotation(camera.rotation.data[0] + dy);
		setZRotation(camera.rotation.data[2] + dx);
	}
	lastPos = event->pos();
}


void GLWidget::wheelEvent(QWheelEvent *event)
{
	camera.pos.inc_z(event->delta()/80.0f);
	updateGL();
	event->accept();
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
	
	glScalef(node_scale, node_scale, node_scale);

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

	glColor3f(0.0f,0.8f,0.8f);
	GLUquadric *p;
	p = gluNewQuadric();
	gluSphere(p,1,8,8);
	/*
	glBegin(GL_TRIANGLE_FAN);		// Drawing Using Triangles
		glVertex3f( 0.0f, 0.5f, 0.0f);				// Top
		glVertex3f(-0.5f, 0.0f, 0.0f);				// Bottom Left
		glVertex3f( 0.0f, 0.0f, 0.5f);				// Bottom Middle
		glVertex3f( 0.5f, 0.0f, 0.0f);				// Bottom Left
		glVertex3f( 0.0f, 0.0f,-0.5f);				// Bottom Middle
		glVertex3f(-0.5f, 0.0f, 0.0f);				// Bottom Left
	glEnd();							// Finished Drawing The Triangle
	glBegin(GL_TRIANGLE_FAN);
		glVertex3f( 0.0f,-0.5f, 0.0f);				// Top
		glVertex3f( 0.0f, 0.0f, 0.5f);				// Bottom Middle
		glVertex3f(-0.5f, 0.0f, 0.0f);				// Bottom Left
		glVertex3f( 0.0f, 0.0f,-0.5f);				// Bottom Middle
		glVertex3f( 0.5f, 0.0f, 0.0f);				// Bottom Left
		glVertex3f( 0.0f, 0.0f, 0.5f);				// Bottom Middle
	glEnd();
	*/
	glPopMatrix();
}


void GLWidget::paintElement(const fem::Element element)
{
	std::map<size_t, fem::Node>::iterator n;
	std::vector<fem::point> nl;	// node list
	fem::point p;
	glPushMatrix();
	switch(element.type)
	{
		case fem::Element::FE_TETRAHEDRON4:
			{
				if(element.nodes.size() != 4)
				{
					qWarning("error: invalid number of nodes for a FE_TETRAHEDRON4");
					//TODO remove element
					return;
				}
				nl.push_back(model->node_list.find(element.nodes[0])->second);
				nl.push_back(model->node_list.find(element.nodes[1])->second);
				nl.push_back(model->node_list.find(element.nodes[2])->second);
				nl.push_back(model->node_list.find(element.nodes[3])->second);
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
				nl.push_back(model->node_list.find(element.nodes[0])->second);
				nl.push_back(model->node_list.find(element.nodes[1])->second);
				nl.push_back(model->node_list.find(element.nodes[2])->second);
				nl.push_back(model->node_list.find(element.nodes[3])->second);
				nl.push_back(model->node_list.find(element.nodes[4])->second);
				nl.push_back(model->node_list.find(element.nodes[5])->second);
				nl.push_back(model->node_list.find(element.nodes[6])->second);
				nl.push_back(model->node_list.find(element.nodes[7])->second);

				/*
				mapsurface[0] = nl[0].data[0];
				mapsurface[1] = nl[0].data[1];
				mapsurface[2] = nl[0].data[2];

				mapsurface[3] = nl[1].data[0];
				mapsurface[4] = nl[1].data[1];
				mapsurface[5] = nl[1].data[2];

				mapsurface[6] = nl[2].data[0];
				mapsurface[7] = nl[2].data[1];
				mapsurface[8] = nl[2].data[2];

				mapsurface[9] = nl[3].data[0];
				mapsurface[10] = nl[3].data[1];
				mapsurface[11] = nl[3].data[2];

				glEnable(GL_MAP2_VERTEX_3);
				glMap2f(GL_MAP2_VERTEX_3,0.0,1.0,3,2,0.0,1.0, 2*3, 1, mapsurface);
				glMapGrid2f(5,0.0, 1.0, 6, 0.0, 1.0);
				glEvalMesh2(GL_LINE, 0, 5, 0, 6);
				*/

				// render the 8-node hexahedron
				/*
				//TODO use glMap2 to build the faces
				glBegin(GL_QUADS);
					// front face
					glColor4f(1,0,0,0.5f);
					glVertex3dv(nl[0].data);
					glVertex3dv(nl[1].data);
					glVertex3dv(nl[2].data);
					glVertex3dv(nl[3].data);

					// back face
					glColor4f(0,1,0,0.5f);
					glVertex3dv(nl[7].data);
					glVertex3dv(nl[6].data);
					glVertex3dv(nl[5].data);
					glVertex3dv(nl[4].data);

					// top face
					glColor4f(0,0,1,0.5f);
					glVertex3dv(nl[3].data);
					glVertex3dv(nl[2].data);
					glVertex3dv(nl[6].data);
					glVertex3dv(nl[7].data);

					// bottom face
					glColor4f(0,0,1,0.5f);
					glVertex3dv(nl[3].data);
					glVertex3dv(nl[2].data);
					glVertex3dv(nl[6].data);
					glVertex3dv(nl[7].data);
				glEnd();
				*/
			}
			break;

		default:
			qWarning("error: unknown element type");
			return;
	}
	glPopMatrix();
}

