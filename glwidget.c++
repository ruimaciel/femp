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

	// initialize the camera
	camera.reset();
	camera.setCenter(0,0,-10);

	setNodeRadiusScale(20);	// default node radius, scaled
	
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
	for(std::map<size_t, fem::Node>::iterator it = model->node_list.begin(); it != model->node_list.end(); it++)
	{
		pos[0] -= it->second.x();
		pos[1] -= it->second.y();
		pos[2] -= it->second.z();
		camera.setPosition(pos[0]/model->node_list.size(),pos[1]/model->node_list.size(),pos[2]/model->node_list.size());
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
}


void GLWidget::resizeGL(int width, int height)
{
	scale = qMin(width, height);
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	
	glOrtho(-(width*2)/(scale), (width*2)/(scale), -height*2/(scale), +height*2/(scale), 2.0, 100.0);
	
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
	else if (event->buttons() & Qt::MidButton) {
		setPosition(camera.pos.data[0] + dx, camera.pos.data[1] + dy);
	}
	lastPos = event->pos();
}


void GLWidget::wheelEvent(QWheelEvent *event)
{
	camera.pos.inc_x(event->delta()/800.0f);
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
	
	glScalef(node_scale*10/scale, node_scale*10/scale, node_scale*10/scale);

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
	glColor3f(0.0f,0.8f,0.8f);
	GLUquadric *p;
	p = gluNewQuadric();
	gluSphere(p,1,8,8);

	// end 
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
		case fem::Element::FE_LINE2:
			{
				if(element.nodes.size() != 2)
				{
					qWarning("error: invalid number of nodes for a FE_LINE2");
					//TODO remove element
					return;
				}
				nl.push_back(model->node_list.find(element.nodes[0])->second);
				nl.push_back(model->node_list.find(element.nodes[1])->second);
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
				nl.push_back(model->node_list.find(element.nodes[0])->second);
				nl.push_back(model->node_list.find(element.nodes[1])->second);
				nl.push_back(model->node_list.find(element.nodes[2])->second);
				glBegin(GL_LINE_STRIP);
				glVertex3dv(nl[0].data);
				glVertex3dv(nl[1].data);
				glVertex3dv(nl[2].data);
				glVertex3dv(nl[0].data);
				glEnd();
			}
			break;

		case fem::Element::FE_TETRAHEDRON4:
			{
				if(element.nodes.size() != 4)
				{
					qWarning("error: invalid number of nodes for a FE_TETRAHEDRON4. it's %zd", element.nodes.size());
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
			}
			break;

		default:
			//qWarning("error: unknown element type: %d", element.type);
			break;
	}
	glPopMatrix();
}

