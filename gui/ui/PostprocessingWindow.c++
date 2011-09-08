#include "PostprocessingWindow.h++"

#include "../viewer/PostprocessingViewport.h++"


PostprocessingWindow::PostprocessingWindow (fem::Project &project, ViewportColors &colors, QWidget *parent)
	: MdiWindow(parent), 
	WindowWithResults(project, colors, parent), 
	WindowWithPostprocessing(project, colors, parent) ,
	WindowWithScaling(project, colors, parent)
{
	this->viewport = new PostprocessingViewport(project,  parent);
	this->viewport->setAnalysisResult(project.result.back());

	this->setCentralWidget(viewport);

	this->viewport->setColors(colors);

	WindowWithScaling::createToolbar(project);
	WindowWithResults::createToolbar(project);
	WindowWithPostprocessing::createToolbar(project);

	connectSignalsToSlots();
}


void PostprocessingWindow::setDisplacementsScale(double scale)
{
	this->viewport->setDisplacementsScale((float)scale);
	this->viewport->refresh();
}


void PostprocessingWindow::setNodeRestrictionsVisibility(const bool )
{
	//TODO run a scenegraph operation
}


void PostprocessingWindow::setGhostSurfacesVisibility(const bool )
{
}

void PostprocessingWindow::connectSignalsToSlots()
{
	WindowWithScaling::connectSignalsToSlots();
	WindowWithPostprocessing::connectSignalsToSlots();

	connect(postprocessingComboBox,	SIGNAL(activated(int)),	this,	SLOT(setPostprocessingState(int)));
}


void PostprocessingWindow::setPostprocessingState(int state)
{
	PostprocessingViewport *current_vp = NULL;
	current_vp = static_cast<PostprocessingViewport*>(this->viewport);
	if(current_vp == NULL)
	{
		return;
	}

	switch(state)
	{
		case A_DISPLACEMENT:
			current_vp->showDisplacements();
			break;

		case A_STRAIN_11:
			current_vp->showStrain11();
			break;

		case A_STRAIN_22:
			current_vp->showStrain22();
			break;

		case A_STRAIN_33:
			current_vp->showStrain33();
			break;

		default:
			qWarning("PostprocessingWindow::setPostprocessingState(%d), unused state", state);
			break;
	}
}


void PostprocessingWindow::setSelection(Selection)
{
}


void PostprocessingWindow::clearSelection()
{
}


void PostprocessingWindow::connectToSelectionManager(SelectionManager &selection_manager)
{
	// connects signals to slots
	std::cout << "void PostprocessingWindow::connectToSelectionManager(SelectionManager &selection_manager)" << std::endl;

	selection_manager.selection_changed.connect( sigc::mem_fun(this, &PostprocessingWindow::setSelection));
	this->selection_changed.connect( sigc::mem_fun(selection_manager, &SelectionManager::setSelection));
}

