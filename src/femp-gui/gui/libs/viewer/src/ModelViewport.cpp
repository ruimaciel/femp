#include <options/Options.hpp>
#include <viewer/ModelViewport.hpp>

#include "SceneGraph.hpp"

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
