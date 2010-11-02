#include "ModelViewport.h++"


ModelViewport::ModelViewport(fem::Model *model, QWidget *parent)
	: QGLWidget(parent), MdiWindowProperties(MdiWindowProperties::MWP_Model)
{
	mylog.setPrefix("ModelViewport::ModelViewport(fem::Model *model, QWidget *parent)");
	mylog.message("constructor");

	assert(model != NULL);

	// initialize the dangling pointers
	this->model = model;

	StateModel.populateScenegraph(model);
	this->state = &StateModel;	// the state's default starting point is Model

	this->state->colors = NULL;

	// set this widget's load pattern pointer
	if(model->load_pattern_list.empty())
	{
		display_options.load_pattern = NULL;
	}
	else
	{
		// set the first load pattern
		display_options.load_pattern = &model->load_pattern_list.front();
	}
}


ModelViewport::~ModelViewport()
{
}


void ModelViewport::setColors(ViewportColors *new_colors)
{
	assert(state->colors != NULL);
	this->state->colors = new_colors;
}


QSize ModelViewport::minimumSizeHint() const
{
	return QSize(50, 50);
}


QSize ModelViewport::sizeHint() const
{
	return QSize(600, 400);
}


void ModelViewport::initializeGL()
{
	// set the state->camera position according to the nodal center
	double pos[3] = {0};
	for(std::map<size_t, fem::Node>::iterator it = model->node_list.begin(); it != model->node_list.end(); it++)
	{
		pos[0] -= it->second.x();
		pos[1] -= it->second.y();
		pos[2] -= it->second.z();
		state->camera.setPosition(pos[0]/model->node_list.size(),pos[1]/model->node_list.size(),pos[2]/model->node_list.size());
	}

	// handle opengl
	this->makeCurrent();
	GLfloat LightAmbient[]= { 0.2f, 0.2f, 0.2f, 1.0f };
	GLfloat LightDiffuse[]= { 0.7f, 0.7f, 0.7f, 1.0f };
	GLfloat LightSpecular[]= { 1.0f, 1.0f, 1.0f, 1.0f };
	GLfloat LightPosition[]= { 0.0f, 0.0f, 0.0f, 1.0f };
	GLfloat specularity[]= { 1.0f, 1.0f, 1.0f, 1.0f };
	GLint specmaterial = 60;

	glClearColor(state->colors->background[0], state->colors->background[1], state->colors->background[2], 0 );

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

}


void ModelViewport::resizeGL(int width, int height)
{
	state->aspect_ratio = qMin(width, height);
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	
	glOrtho(-(width*2)/(state->aspect_ratio*pow(2,state->zoom)), (width*2)/(state->aspect_ratio*pow(2,state->zoom)), -height*2/(state->aspect_ratio*pow(2,state->zoom)), +height*2/(state->aspect_ratio*pow(2,state->zoom)), 0.1, 1000.0);
	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}


void ModelViewport::paintGL()
{
	assert(model != NULL);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	state->paintGL(model, state->colors);
}


void ModelViewport::mousePressEvent(QMouseEvent *event)
{
	state->mousePressEvent(event);

	updateGL();
}


void ModelViewport::mouseMoveEvent(QMouseEvent *event)
{
	int dx = event->x() - state->lastPos.x();
	int dy = event->y() - state->lastPos.y();

	if (event->buttons() & Qt::LeftButton) 
	{
		//TODO set action for left click button
	} else if (event->buttons() & Qt::RightButton) 
	{
		setXRotation(state->camera.rotation.data[0] + dy);
		setYRotation(state->camera.rotation.data[1] + dx);
	}

	state->lastPos = event->pos();

	updateGL();
}


void ModelViewport::wheelEvent(QWheelEvent *event)
{
	state->zoom += event->delta()/1000.0f;
	//qWarning("state->zoom: %f, %f",state->zoom, pow(2,state->zoom));

	this->resizeGL(this->width(), this->height());
	this->updateGL();
	event->accept();
}


void ModelViewport::setXRotation(int angle)
{
	normalizeAngle(&angle);
	state->camera.rotation.data[0] = angle;
	Q_EMIT xRotationChanged(angle);
	updateGL();
}


void ModelViewport::setYRotation(int angle)
{
	normalizeAngle(&angle);
	state->camera.rotation.data[1] = angle;
	Q_EMIT yRotationChanged(angle);
	updateGL();
}


void ModelViewport::setZRotation(int angle)
{
	normalizeAngle(&angle);
	state->camera.rotation.data[2] = angle;
	Q_EMIT zRotationChanged(angle);
	updateGL();
}


void ModelViewport::setPosition(int x, int y)
{
	mylog.setPrefix("ModelViewport::setPosition(int x, int y)");
	//TODO implement this
	state->camera.pos.x(-x);
	state->camera.pos.y(-y);
	//state->camera.pos.z(amount/100.0f);
	//qWarning("pos: %f, %f, %f",state->camera.pos.x(), state->camera.pos.y(), state->camera.pos.z());
	QString m;
	mylog.message(m.sprintf("pos: %f, %f, %f",state->camera.pos.x(), state->camera.pos.y(), state->camera.pos.z()));

	updateGL();

	mylog.clearPrefix();
}


void ModelViewport::normalizeAngle(int *angle)
{
	while (*angle < 0)
		*angle += 360 * 16;
	while (*angle > 360 * 16)
		*angle -= 360 * 16;
}


