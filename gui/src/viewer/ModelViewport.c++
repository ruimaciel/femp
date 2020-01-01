#include "ModelViewport.h++"

#include "SceneGraph.h++"

#include <options/Options.h++>

ModelViewport::ModelViewport(fem::Project& project, QWidget* parent)
    : BaseViewport(project, parent)
{
    // initialize the dangling pointers
    this->state = nullptr;

    this->setState(&m_vp_state_model); // set the current viewport state

    // set this widget's load pattern pointer
    if (project.getModel().load_pattern_list.empty()) {
        Options::getInstance().getDisplayOptions().load_pattern = nullptr;
    } else {
        // set the first load pattern
        Options::getInstance().getDisplayOptions().load_pattern = &project.getModel().load_pattern_list.front();
    }
    this->setFocusPolicy(Qt::StrongFocus);
}

ModelViewport::~ModelViewport()
{
}

void ModelViewport::showModel()
{
    // set the state
    VPStateModel* state = &m_vp_state_model;

    this->setState(state);
}
