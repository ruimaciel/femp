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
	if(project.getModel().load_pattern_list.empty())
	{
		display_options.load_pattern = NULL;
	}
	else
	{
		// set the first load pattern
		display_options.load_pattern = &project.getModel().load_pattern_list.front();
	}
	this->setFocusPolicy(Qt::StrongFocus);
}


ModelViewport::~ModelViewport()
{
}


void 
ModelViewport::showModel()
{
	// set the state
	VPStateModel* state = &m_vp_state_model;

	this->setState(state);

}



