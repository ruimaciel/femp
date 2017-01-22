#include "ViewportState.h++"

#include <GL/gl.h>
#include <GL/glu.h>

#include "../SceneGraphComponents/SGCPickRay.h++"	// debugging purposes only


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
ViewportState::setRenderGroupVisibility(SceneGraph::Groups group, bool state)
{
	this->scenegraph.rendering_groups[group].render = state;
}


void
ViewportState::paintGL(BaseViewport *viewport)
{
	assert(viewport != NULL);

	viewport->viewport_data.camera.reposition();

	this->scenegraph.paint(viewport->viewport_data,  viewport->colors);
}


void
ViewportState::mousePressEvent(BaseViewport *viewport, QMouseEvent *event)
{
	viewport->viewport_data.lastPos = event->pos();
	// process left clicks
	if(event->buttons() & Qt::LeftButton)
	{
		fem::Point near, far;
		QPoint pos = event->pos();
		
		GLint vport[4];

		glGetDoublev(GL_MODELVIEW_MATRIX, viewport->viewport_data.modelview);
		glGetDoublev(GL_PROJECTION_MATRIX, viewport->viewport_data.projection);
		glGetIntegerv(GL_VIEWPORT, vport);
		gluUnProject(pos.x(), vport[3]-pos.y(), 0, viewport->viewport_data.modelview, viewport->viewport_data.projection, vport, &near.data[0], &near.data[1], &near.data[2]);
		gluUnProject(pos.x(), vport[3]-pos.y(), 1, viewport->viewport_data.modelview, viewport->viewport_data.projection, vport, &far.data[0], &far.data[1], &far.data[2]);
	}
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
ViewportState::runSceneGraphOperation(Operation::OperationsVisitor &visitor)
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


void 
ViewportState::setSelectionStart(fem::Point const &p)
{ 
	std::cerr << "ViewportState::setSelectionStart(fem::Point) 	=> (" << p.x() << ", " << p.y() << ", " << p.z() << ")" << std::endl;
	scenegraph.setSelectionStart(p); 
};


void 
ViewportState::setSelectionEnd(fem::Point const &p)
{ 
	std::cerr << "ViewportState::setSelectionEnd(fem::Point) 	=> (" << p.x() << ", " << p.y() << ", " << p.z() << ")" << std::endl;
	scenegraph.setSelectionEnd(p); 
};


void 
ViewportState::setSelectionOff()
{
	scenegraph.setSelectionOff();
}


void 
ViewportState::addPickRay(fem::Point const &origin, fem::Point const &destination, float const &radius)
{
	std::cerr << "ViewportState::addPickRay(fem::Point const &origin, fem::Point const &destination, float const &radius)" << std::endl;
	SGC::PickRay *ray = new SGC::PickRay(origin, destination, radius);
	scenegraph.addPrimitiveComponent(SceneGraph::RG_NODES, ray);
	scenegraph.generateSceneGraph();
}


void 
ViewportState::setTrianglesVisible(bool const)
{
}

