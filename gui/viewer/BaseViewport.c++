#include "BaseViewport.h++"


BaseViewport::BaseViewport(fem::Project &project, QWidget *parent)
	: QGLWidget(parent)
{
	assert(parent != NULL);

	// initialize the dangling pointers
	this->project = &project;

	this->state = NULL;

	this->setFocusPolicy(Qt::StrongFocus);
}


void BaseViewport::setColors(ViewportColors &new_colors)
{
	colors = new_colors;
}


QSize BaseViewport::minimumSizeHint() const
{
	return QSize(50, 50);
}


QSize BaseViewport::sizeHint() const
{
	return QSize(600, 400);
}


void BaseViewport::initializeGL()
{
	// set the state->camera position according to the nodal center
	double pos[3] = {0};
	for(std::map<size_t, fem::Node>::iterator it = project->model.node_list.begin(); it != project->model.node_list.end(); it++)
	{
		pos[0] -= it->second.x();
		pos[1] -= it->second.y();
		pos[2] -= it->second.z();

		viewport_data.camera.reset();
		viewport_data.camera.setCenter(0,0,-500);
		viewport_data.camera.setPosition(pos[0]/project->model.node_list.size(),pos[1]/project->model.node_list.size(),pos[2]/project->model.node_list.size());
	}

	// handle opengl
	this->makeCurrent();
	GLfloat LightAmbient[]= { 0.2f, 0.2f, 0.2f, 1.0f };
	GLfloat LightDiffuse[]= { 0.7f, 0.7f, 0.7f, 1.0f };
	GLfloat LightSpecular[]= { 1.0f, 1.0f, 1.0f, 1.0f };
	GLfloat LightPosition[]= { 0.0f, 0.0f, 0.0f, 1.0f };
	GLfloat specularity[]= { 1.0f, 1.0f, 1.0f, 1.0f };
	GLint specmaterial = 60;

	glClearDepth(1.0f);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	glEnable(GL_CULL_FACE);

	glEnable(GL_NORMALIZE);

	// set antialias options
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

	//glEnable(GL_BLEND);
	glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

}


void BaseViewport::resizeGL(int width, int height)
{
	viewport_data.aspect_ratio = qMin(width, height);
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	
	glOrtho(-(width*2)/(viewport_data.aspect_ratio*pow(2,viewport_data.zoom)), (width*2)/(viewport_data.aspect_ratio*pow(2,viewport_data.zoom)), -height*2/(viewport_data.aspect_ratio*pow(2,viewport_data.zoom)), +height*2/(viewport_data.aspect_ratio*pow(2,viewport_data.zoom)), 0.1, 1000.0);
	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}


void BaseViewport::paintGL()
{
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	state->paintGL(this);
}


void BaseViewport::mousePressEvent(QMouseEvent *event)
{
	state->mousePressEvent(this, event);

	updateGL();
}


void BaseViewport::mouseMoveEvent(QMouseEvent *event)
{
	state->mouseMoveEvent(this, event);

	updateGL();
}


void BaseViewport::wheelEvent(QWheelEvent *event)
{
	viewport_data.zoom += event->delta()/1000.0f;
	//qWarning("viewport_data.zoom: %f, %f",viewport_data.zoom, pow(2,viewport_data.zoom));

	this->resizeGL(this->width(), this->height());
	this->updateGL();
	event->accept();
}


void BaseViewport::keyPressEvent( QKeyEvent *event)
{
	state->keyPressEvent(this, event);
}


void BaseViewport::setState(ViewportState<BaseViewport> *new_state)
{
	if(this->state != NULL) delete this->state;

	this->state = new_state;
	this->state->initialize(this);
	this->state->populateScenegraph(this);
}


void BaseViewport::setXRotation(int angle)
{
	normalizeAngle(&angle);
	viewport_data.camera.rotation.data[0] = angle;
	Q_EMIT xRotationChanged(angle);
	updateGL();
}


void BaseViewport::setYRotation(int angle)
{
	normalizeAngle(&angle);
	viewport_data.camera.rotation.data[1] = angle;
	Q_EMIT yRotationChanged(angle);
	updateGL();
}


void BaseViewport::setZRotation(int angle)
{
	normalizeAngle(&angle);
	viewport_data.camera.rotation.data[2] = angle;
	Q_EMIT zRotationChanged(angle);
	updateGL();
}


void BaseViewport::setPosition(int x, int y)
{
	//TODO implement this
	viewport_data.camera.pos.x(-x);
	viewport_data.camera.pos.y(-y);

	updateGL();
}


void BaseViewport::setAnalysisResult(fem::AnalysisResult<double> &new_result)
{
	this->state->setAnalysisResult(new_result);
}


void BaseViewport::setDisplacementsScale(float scale)
{
	this->state->setDisplacementsScale(scale);
}


void BaseViewport::normalizeAngle(int *angle)
{
	while (*angle < 0)
		*angle += 360 * 16;
	while (*angle > 360 * 16)
		*angle -= 360 * 16;
}



