#include "ModelViewport.h++"

#include <options/Options.h++>

#include "SceneGraph.h++"

ModelViewport::ModelViewport(fem::Project& project, QWidget* parent) : BaseViewport(project, parent) {
	// initialize the dangling pointers
	this->state = nullptr;

	this->setState(&m_vp_state_model);	// set the current viewport state

	this->setFocusPolicy(Qt::StrongFocus);
}

ModelViewport::~ModelViewport() {}

void ModelViewport::showModel() {
	// set the state
	VPStateModel* state = &m_vp_state_model;

	this->setState(state);
}
