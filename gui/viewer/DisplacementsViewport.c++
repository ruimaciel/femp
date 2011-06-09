#include "DisplacementsViewport.h++"


DisplacementsViewport::DisplacementsViewport(fem::Project &project, QWidget *parent)
	: BaseViewport(project, parent)
{
	mylog.setPrefix("DisplacementsViewport::DisplacementsViewport(fem::Model *model, QWidget *parent)");
	mylog.message("constructor");

	//TODO let the user choose which result to represent
	this->showDisplacements(project.result.back());

	// set this widget's load pattern pointer
	if(project.model.load_pattern_list.empty())
	{
		display_options.load_pattern = NULL;
	}
	else
	{
		// set the first load pattern
		display_options.load_pattern = &project.model.load_pattern_list.front();
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


void DisplacementsViewport::setNodeVisibility(bool state)
{
	this->state->setRenderGoupVisibility(SceneGraph::RG_NODES, state);
	this->display_options.nodes = state;
}


void DisplacementsViewport::setSurfaceVisibility(bool state)
{
	this->state->setRenderGoupVisibility(SceneGraph::RG_SURFACES, state);
	this->state->setRenderGoupVisibility(SceneGraph::RG_WIREFRAME, !state);
	this->display_options.surfaces = state;
}


void DisplacementsViewport::paintGL()
{
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


