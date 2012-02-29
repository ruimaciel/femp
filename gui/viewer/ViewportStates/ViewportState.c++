#include "ViewportState.h++"


ViewportState::ViewportState()
{
}


ViewportState::~ViewportState()
{
	this->scenegraph.clear();

}


void
ViewportState::setAnalysisResult(fem::AnalysisResult<double> &)
{
}


void
ViewportState::setDisplacementsScale(float new_scale)
{
	this->scale = new_scale;
}


void
ViewportState::setRenderGoupVisibility(SceneGraph::Groups group, bool state)
{
	this->scenegraph.rendering_groups[group].render = state;
}


void
ViewportState::paintGL(BaseViewport *viewport)
{
	assert(viewport != NULL);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	viewport->viewport_data.camera.reposition();

	this->scenegraph.paint(viewport->viewport_data,  viewport->colors);
}


void
ViewportState::mouseMoveEvent(BaseViewport *viewport, QMouseEvent *event)
{
	assert(viewport != NULL);

	int dx = event->x() - viewport->viewport_data.lastPos.x();
	int dy = event->y() - viewport->viewport_data.lastPos.y();

	if (event->buttons() & Qt::LeftButton) 
	{
		//TODO set action for left click button
	} else if (event->buttons() & Qt::RightButton) 
	{
		viewport->viewport_data.camera.rotation.data[0] += dy/pow(2,viewport->viewport_data.zoom);
		viewport->viewport_data.camera.rotation.data[1] += dx/pow(2,viewport->viewport_data.zoom);
	}

	viewport->viewport_data.lastPos = event->pos();
}


void
ViewportState::keyPressEvent ( BaseViewport *, QKeyEvent * event )
{
	event->ignore();
}


void 
ViewportState::runSceneGraphOperation(OperationsVisitor &visitor)
{
	scenegraph.runOperation(visitor);
}


void
ViewportState::setSelection(Selection)
{
}


void 
ViewportState::clearSelection()
{
}


void 
ViewportState::showSelection(const Selection)
{
	std::cout << "ViewportState::showSelection(const Selection selection)" << std::endl;
}


