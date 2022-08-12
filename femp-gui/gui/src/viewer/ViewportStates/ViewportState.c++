#include "ViewportState.h++"

#include <GL/gl.h>
#include <GL/glu.h>

#include <QDebug>

#include "../BaseViewport.h++"
#include "../SceneGraphComponents/SGCPickRay.h++"  // debugging purposes only

ViewportState::~ViewportState() { this->scenegraph.clear(); }

void ViewportState::setAnalysisResult(fem::AnalysisResult&) {}

void ViewportState::setDisplacementsScale(float new_scale) { this->scale = new_scale; }

void ViewportState::setRenderGroupVisibility(SceneGraph::Groups group, bool state) { this->scenegraph.rendering_groups[group].setVisible(state); }

void ViewportState::paintGL(BaseViewport* viewport) {
	assert(viewport != nullptr);

	viewport->viewport_data.camera.reposition();

	this->scenegraph.paint(viewport->viewport_data, viewport->getColors());
}

void ViewportState::mousePressEvent(BaseViewport* viewport, QMouseEvent* event) {
	viewport->viewport_data.lastPos = event->pos();
	// process left clicks
	if (event->buttons() & Qt::LeftButton) {
		fem::Point3D near, far;
		QPoint pos = event->pos();

		GLint vport[4];

		glGetDoublev(GL_MODELVIEW_MATRIX, viewport->viewport_data.modelview);
		glGetDoublev(GL_PROJECTION_MATRIX, viewport->viewport_data.projection);
		glGetIntegerv(GL_VIEWPORT, vport);
		gluUnProject(pos.x(), vport[3] - pos.y(), 0, viewport->viewport_data.modelview, viewport->viewport_data.projection, vport, &near.data[0], &near.data[1],
					 &near.data[2]);
		gluUnProject(pos.x(), vport[3] - pos.y(), 1, viewport->viewport_data.modelview, viewport->viewport_data.projection, vport, &far.data[0], &far.data[1],
					 &far.data[2]);
	}
}

void ViewportState::mouseMoveEvent(BaseViewport* viewport, QMouseEvent* event) {
	assert(viewport != nullptr);

	int dx = event->x() - viewport->viewport_data.lastPos.x();
	int dy = event->y() - viewport->viewport_data.lastPos.y();

	if (event->buttons() & Qt::LeftButton) {
		// TODO set action for left click button
	} else if (event->buttons() & Qt::RightButton) {
		fem::Point3D rotation = viewport->viewport_data.camera.getRotation();
		rotation.data[0] += dy / pow(2, viewport->viewport_data.zoom);
		rotation.data[1] += dx / pow(2, viewport->viewport_data.zoom);
		viewport->viewport_data.camera.setRotation(rotation);
	}

	viewport->viewport_data.lastPos = event->pos();
}

void ViewportState::keyPressEvent(BaseViewport*, QKeyEvent* event) { event->ignore(); }

void ViewportState::runSceneGraphOperation(Operation::OperationsVisitor& visitor) { scenegraph.runOperation(visitor); }

void ViewportState::setSelection(Selection) {}

void ViewportState::clearSelection() {}

void ViewportState::showSelection(const Selection) { qInfo() << "ViewportState::showSelection(const Selection selection)"; }

void ViewportState::setSelectionStart(fem::Point3D const& p) {
	qInfo() << "ViewportState::setSelectionStart(fem::Point) 	=> (" << p.x() << ", " << p.y() << ", " << p.z() << ")";
	scenegraph.setSelectionStart(p);
};

void ViewportState::setSelectionEnd(fem::Point3D const& p) {
	qInfo() << "ViewportState::setSelectionEnd(fem::Point) 	=> (" << p.x() << ", " << p.y() << ", " << p.z() << ")";
	scenegraph.setSelectionEnd(p);
};

void ViewportState::setSelectionOff() { scenegraph.setSelectionOff(); }

void ViewportState::addPickRay(fem::Point3D const& origin, fem::Point3D const& destination, float const& radius) {
	qInfo() << "ViewportState::addPickRay(fem::Point const &origin, fem::Point "
			   "const &destination, float const &radius)";
	SGC::PickRay* ray = new SGC::PickRay(origin, destination, radius);
	scenegraph.addPrimitiveComponent(SceneGraph::RG_NODES, std::shared_ptr<SceneGraphComponent>(ray));
	scenegraph.generateSceneGraph();
}

void ViewportState::setTrianglesVisible(bool const) { qInfo() << "ViewportState::setTrianglesVisible(bool const)"; }
