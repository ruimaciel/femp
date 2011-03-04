#include "DisplacementsViewport.h++"


DisplacementsViewport::DisplacementsViewport(fem::Model *model, fem::AnalysisResult<double> &analysis, QWidget *parent)
	: QGLWidget(parent), MdiWindowProperties(MdiWindowProperties::MWP_Displacements)
{
	this->analysis_result = &analysis;

	mylog.setPrefix("DisplacementsViewport::DisplacementsViewport(fem::Model *model, QWidget *parent)");
	mylog.message("constructor");

	assert(model != NULL);

	// initialize the dangling pointers
	this->model = model;
	this->state = NULL;

	//this->setState(new VPStateDisplacements);	// set the current viewport state
	this->showDisplacements(*this->analysis_result);

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
	this->setFocusPolicy(Qt::StrongFocus);
}


DisplacementsViewport::~DisplacementsViewport()
{
}


void DisplacementsViewport::setColors(ViewportColors &new_colors)
{
	colors = new_colors;
}


QSize DisplacementsViewport::minimumSizeHint() const
{
	return QSize(50, 50);
}


QSize DisplacementsViewport::sizeHint() const
{
	return QSize(600, 400);
}


void DisplacementsViewport::initializeGL()
{
	// set the state->camera position according to the nodal center
	double pos[3] = {0};
	for(std::map<size_t, fem::Node>::iterator it = model->node_list.begin(); it != model->node_list.end(); it++)
	{
		pos[0] -= it->second.x();
		pos[1] -= it->second.y();
		pos[2] -= it->second.z();

		viewport_data.camera.reset();
		viewport_data.camera.setCenter(0,0,-500);
		viewport_data.camera.setPosition(pos[0]/model->node_list.size(),pos[1]/model->node_list.size(),pos[2]/model->node_list.size());
	}

	// handle opengl
	this->makeCurrent();
	GLfloat LightAmbient[]= { 0.2f, 0.2f, 0.2f, 1.0f };
	GLfloat LightDiffuse[]= { 0.7f, 0.7f, 0.7f, 1.0f };
	GLfloat LightSpecular[]= { 1.0f, 1.0f, 1.0f, 1.0f };
	GLfloat LightPosition[]= { 0.0f, 0.0f, 0.0f, 1.0f };
	GLfloat specularity[]= { 1.0f, 1.0f, 1.0f, 1.0f };
	GLint specmaterial = 60;

	//glClearColor(colors.background[0], colors.background[1], colors.background[2], 0 );

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


void DisplacementsViewport::resizeGL(int width, int height)
{
	viewport_data.aspect_ratio = qMin(width, height);
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	
	glOrtho(-(width*2)/(viewport_data.aspect_ratio*pow(2,viewport_data.zoom)), (width*2)/(viewport_data.aspect_ratio*pow(2,viewport_data.zoom)), -height*2/(viewport_data.aspect_ratio*pow(2,viewport_data.zoom)), +height*2/(viewport_data.aspect_ratio*pow(2,viewport_data.zoom)), 0.1, 1000.0);
	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}


void DisplacementsViewport::paintGL()
{
	assert(model != NULL);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	state->paintGL(this);
}


void DisplacementsViewport::mousePressEvent(QMouseEvent *event)
{
	state->mousePressEvent(this, event);

	updateGL();
}


void DisplacementsViewport::mouseMoveEvent(QMouseEvent *event)
{
	state->mouseMoveEvent(this, event);

	updateGL();
}


void DisplacementsViewport::wheelEvent(QWheelEvent *event)
{
	viewport_data.zoom += event->delta()/1000.0f;
	//qWarning("viewport_data.zoom: %f, %f",viewport_data.zoom, pow(2,viewport_data.zoom));

	this->resizeGL(this->width(), this->height());
	this->updateGL();
	event->accept();
}


void DisplacementsViewport::keyPressEvent( QKeyEvent *event)
{
	qWarning("blah not keypressed");
	state->keyPressEvent(this, event);
}


template <class NewState>
void DisplacementsViewport::setState(NewState *new_state)
{
	if(this->state != NULL) delete this->state;

	this->state = new_state;
	this->state->initialize(this);
	this->state->populateScenegraph(this);
}


void DisplacementsViewport::setXRotation(int angle)
{
	normalizeAngle(&angle);
	viewport_data.camera.rotation.data[0] = angle;
	Q_EMIT xRotationChanged(angle);
	updateGL();
}


void DisplacementsViewport::setYRotation(int angle)
{
	normalizeAngle(&angle);
	viewport_data.camera.rotation.data[1] = angle;
	Q_EMIT yRotationChanged(angle);
	updateGL();
}


void DisplacementsViewport::setZRotation(int angle)
{
	normalizeAngle(&angle);
	viewport_data.camera.rotation.data[2] = angle;
	Q_EMIT zRotationChanged(angle);
	updateGL();
}


void DisplacementsViewport::setPosition(int x, int y)
{
	mylog.setPrefix("DisplacementsViewport::setPosition(int x, int y)");
	//TODO implement this
	viewport_data.camera.pos.x(-x);
	viewport_data.camera.pos.y(-y);
	//viewport_data.camera.pos.z(amount/100.0f);
	//qWarning("pos: %f, %f, %f",viewport_data.camera.pos.x(), viewport_data.camera.pos.y(), viewport_data.camera.pos.z());
	QString m;
	mylog.message(m.sprintf("pos: %f, %f, %f",viewport_data.camera.pos.x(), viewport_data.camera.pos.y(), viewport_data.camera.pos.z()));

	updateGL();

	mylog.clearPrefix();
}


/*
void DisplacementsViewport::showModel()
{
	// set the state
	VPStateModel* state = new VPStateModel;

	this->setState(state);
}
*/


void DisplacementsViewport::showDisplacements(fem::AnalysisResult<double> &analysis)
{
	// setup the displacements map

	// set the state
	VPStateDisplacements* state = new VPStateDisplacements;

	this->setState(state);
	state->setDisplacements(analysis);
}


void DisplacementsViewport::normalizeAngle(int *angle)
{
	while (*angle < 0)
		*angle += 360 * 16;
	while (*angle > 360 * 16)
		*angle -= 360 * 16;
}


