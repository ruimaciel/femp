#include "PostprocessingWindow.h++"

#include "../viewer/PostprocessingViewport.h++"

#include <map>
#include "ResultsRangeDialog.h++"
#include "../fem/ElementResults/ElementResults.h++"



PostprocessingWindow::PostprocessingWindow (fem::Project &project, fem::AnalysisResult<double> &result, ViewportColors &colors, QWidget *parent)
	: MdiWindow(parent), 
	WindowWithResults(project, colors, parent), 
	WindowWithPostprocessing(project, colors, parent) ,
	WindowWithScaling(project, colors, parent)
{
	this->setGradientValuesRange(result);
	this->viewport = new PostprocessingViewport(project, result, m_results_ranges,  parent);

	this->setCentralWidget(viewport);

	this->viewport->setColors(colors);


	WindowWithScaling::createMenuBar(this->menuBar());

	this->createToolBars(project);

	connectSignalsToSlots();
}


void 
PostprocessingWindow::setDisplacementsScale(double scale)
{
	this->viewport->setDisplacementsScale((float)scale);
	this->viewport->refresh();
}


void 
PostprocessingWindow::setNodeRestrictionsVisibility(const bool )
{
	//TODO run a scenegraph operation
	qWarning(" void PostprocessingWindow::setNodeRestrictionsVisibility(const bool )");
}


void 
PostprocessingWindow::setGhostSurfacesVisibility(const bool )
{
}


void 
PostprocessingWindow::setAnalysisResult(fem::AnalysisResult<double> &result)
{
	this->m_result = &result;
	this->setGradientValuesRange(result);
	this->viewport->setAnalysisResult(result);
}


void 
PostprocessingWindow::connectSignalsToSlots()
{
	WindowWithScaling::connectSignalsToSlots();
	WindowWithPostprocessing::connectSignalsToSlots();

	connect(postprocessingComboBox,	SIGNAL(activated(int)),	this,	SLOT(setPostprocessingState(int)));
	connect(actionMenuVisibility,	SIGNAL(toggled(bool)),	this,	SLOT(toggleMenuBarVisibility(bool) ) );
	connect(actionSetTensionRanges,	SIGNAL(triggered()),	this,	SLOT(setResultsRanges()));
}


void 
PostprocessingWindow::createToolBars(fem::Project &project)
{
	WindowWithScaling::createToolbar(project);
	WindowWithResults::createToolbar(project);
	WindowWithPostprocessing::createToolbar(project);

	// create
	toggleMenuBarVisibilityToolBar = addToolBar(tr("Menu bar visibility"));
	toggleMenuBarVisibilityToolBar->addAction(actionMenuVisibility);
}


void 
PostprocessingWindow::setGradientValuesRange(const fem::AnalysisResult<double> &result)
{
	//TODO finish this
	this->m_results_ranges = result.ranges;
}


void 
PostprocessingWindow::toggleMenuBarVisibility(bool visibility)
{
	qWarning("void PostprocessingWindow::toggleMenuBarVisibility(bool visibility) ");
	this->menuBar()->setVisible(visibility);
}


void 
PostprocessingWindow::setResultsRanges()
{
	ResultsRangeDialog dialog(this);
	dialog.setValueRanges(this->m_results_ranges);

	switch(dialog.exec())
	{
		case QDialog::Accepted:
			dialog.getValueRanges(this->m_results_ranges);
			break;

		default:
			break;
	};
}


void 
PostprocessingWindow::setPostprocessingState(int state)
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

		case A_STRAIN_12:
			current_vp->showStrain12();
			break;

		case A_STRAIN_23:
			current_vp->showStrain23();
			break;

		case A_STRAIN_13:
			current_vp->showStrain13();
			break;

		case A_STRESS_11:
			current_vp->showStress11();
			break;

		case A_STRESS_22:
			current_vp->showStress22();
			break;

		case A_STRESS_33:
			current_vp->showStress33();
			break;

		case A_STRESS_12:
			current_vp->showStress12();
			break;

		case A_STRESS_23:
			current_vp->showStress23();
			break;

		case A_STRESS_13:
			current_vp->showStress13();
			break;

		case A_VON_MISES:
			current_vp->showVonMises();
			break;

		case A_TENSION_FIELD:
			current_vp->showTensionField();
			break;

		default:
			qWarning(" PostprocessingWindow::setPostprocessingState(%d), unused state", state);
			break;
	}
}


void 
PostprocessingWindow::setSelection(Selection)
{
}


void 
PostprocessingWindow::clearSelection()
{
}


void 
PostprocessingWindow::connectToSelectionManager(SelectionManager &selection_manager)
{
	// connects signals to slots
	std::cout << "void PostprocessingWindow::connectToSelectionManager(SelectionManager &selection_manager)" << std::endl;

	selection_manager.selection_changed.connect( sigc::mem_fun(this, & PostprocessingWindow::setSelection));
	this->selection_changed.connect( sigc::mem_fun(selection_manager, &SelectionManager::setSelection));
}

