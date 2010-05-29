#include "glBaseWidget.h++"


GLBaseWidget::GLBaseWidget(Document *document, QWidget *parent)
	: QGLWidget(parent)
{
	// initialize the dangling pointers
	this->document = document;
	this->colors = NULL;
}


GLBaseWidget::~GLBaseWidget()
{
}


/*
Sets which fem::Model object this widget will render
*/
void GLBaseWidget::setDocument(Document *document)
{
	assert(document != NULL);
	this->document = document;
}


void GLBaseWidget::setColors(ViewportColors *colors)
{
	assert(colors != NULL);
	this->colors = colors;
}


QSize GLBaseWidget::minimumSizeHint() const
{
	return QSize(50, 50);
}


QSize GLBaseWidget::sizeHint() const
{
	return QSize(600, 400);
}


void GLBaseWidget::initializeGL()
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


void GLBaseWidget::resizeGL(int width, int height)
{
	aspect_ratio = qMin(width, height);
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	
	glOrtho(-(width*2)/(aspect_ratio*pow(2,zoom)), (width*2)/(aspect_ratio*pow(2,zoom)), -height*2/(aspect_ratio*pow(2,zoom)), +height*2/(aspect_ratio*pow(2,zoom)), 0.1, 1000.0);
	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	
	// generate display lists
	generateDisplayLists();	// put in place to preserve the aspect_ratio of certain drawing components
}


void GLBaseWidget::paintArrow(const fem::point &p, const fem::point &direction)
{
	// draw line
	glBegin(GL_LINES);
	glVertex3dv(p.data);
	glVertex3dv((p + direction).data);
	glEnd();
}


void GLBaseWidget::setXRotation(int angle)
{
	normalizeAngle(&angle);
	camera.rotation.data[0] = angle;
	Q_EMIT xRotationChanged(angle);
	updateGL();
}


void GLBaseWidget::setYRotation(int angle)
{
	normalizeAngle(&angle);
	camera.rotation.data[1] = angle;
	Q_EMIT yRotationChanged(angle);
	updateGL();
}


void GLBaseWidget::setZRotation(int angle)
{
	normalizeAngle(&angle);
	camera.rotation.data[2] = angle;
	Q_EMIT zRotationChanged(angle);
	updateGL();
}


void GLBaseWidget::setPosition(int x, int y)
{
	//TODO implement this
	camera.pos.x(-x);
	camera.pos.y(-y);
	//camera.pos.z(amount/100.0f);
	qWarning("pos: %f, %f, %f",camera.pos.x(), camera.pos.y(), camera.pos.z());
	updateGL();
}


void GLBaseWidget::normalizeAngle(int *angle)
{
	while (*angle < 0)
		*angle += 360 * 16;
	while (*angle > 360 * 16)
		*angle -= 360 * 16;
}


