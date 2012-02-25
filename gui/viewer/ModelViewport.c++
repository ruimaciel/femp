#include "ModelViewport.h++"

#include "SceneGraph.h++"



ModelViewport::ModelViewport(fem::Project &project, QWidget *parent)
	: BaseViewport(project, parent)
{
	// initialize the dangling pointers
	this->project = &project;
	this->state = NULL;

	this->setState(&m_vp_state_model);	// set the current viewport state

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


ModelViewport::~ModelViewport()
{
}


void 
ModelViewport::setNodeVisibility(bool state)
{
	this->state->setRenderGoupVisibility(SceneGraph::RG_NODES, state);
	this->display_options.nodes = state;
}


void 
ModelViewport::setSurfaceVisibility(bool state)
{
	this->state->setRenderGoupVisibility(SceneGraph::RG_SURFACES, state);
	this->state->setRenderGoupVisibility(SceneGraph::RG_WIREFRAME, !state);
	this->display_options.surfaces = state;
}


void 
ModelViewport::paintGL()
{
	assert(project != NULL);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	state->paintGL(this);
}


void 
ModelViewport::mousePressEvent(QMouseEvent *event)
{
	state->mousePressEvent(this, event);

	updateGL();
}


void 
ModelViewport::mouseMoveEvent(QMouseEvent *event)
{
	state->mouseMoveEvent(this, event);

	updateGL();
}


void 
ModelViewport::wheelEvent(QWheelEvent *event)
{
	viewport_data.zoom += event->delta()/1000.0f;

	this->resizeGL(this->width(), this->height());
	this->updateGL();
	event->accept();
}


void 
ModelViewport::keyPressEvent( QKeyEvent *event)
{
	state->keyPressEvent(this, event);
}


void 
ModelViewport::setXRotation(int angle)
{
	normalizeAngle(&angle);
	viewport_data.camera.rotation.data[0] = angle;
	Q_EMIT xRotationChanged(angle);
	updateGL();
}


void 
ModelViewport::setYRotation(int angle)
{
	normalizeAngle(&angle);
	viewport_data.camera.rotation.data[1] = angle;
	Q_EMIT yRotationChanged(angle);
	updateGL();
}


void 
ModelViewport::setZRotation(int angle)
{
	normalizeAngle(&angle);
	viewport_data.camera.rotation.data[2] = angle;
	Q_EMIT zRotationChanged(angle);
	updateGL();
}


void 
ModelViewport::setPosition(int x, int y)
{
	//TODO implement this
	viewport_data.camera.pos.x(-x);
	viewport_data.camera.pos.y(-y);

	updateGL();
}


void 
ModelViewport::showModel()
{
	// set the state
	VPStateModel* state = &m_vp_state_model;

	this->setState(state);

}



