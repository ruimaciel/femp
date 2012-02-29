#include "TensorFieldWindow.h++"

#include "../viewer/TensorFieldViewport.h++"

#include <map>
#include "ResultsRangeDialog.h++"
#include "../fem/ElementResults/ElementResults.h++"



TensorFieldWindow::TensorFieldWindow (fem::Project &project, fem::AnalysisResult<double> &result, ViewportColors &colors, QWidget *parent)
	: MdiWindow(parent), 
	WindowWithResults(project, colors, parent), 
	WindowWithScaling(project, colors, parent)
{
	this->setGradientValuesRange(result);
	this->viewport = new TensorFieldViewport(project, result, m_results_ranges,  parent);

	this->setCentralWidget(viewport);

	this->viewport->setColors(colors);


	WindowWithScaling::createMenuBar(this->menuBar());

	this->createToolBars(project);

	connectSignalsToSlots();
}


void 
TensorFieldWindow::setDisplacementsScale(double scale)
{
	this->viewport->setDisplacementsScale((float)scale);
	this->viewport->refresh();
}


void 
TensorFieldWindow::setNodeRestrictionsVisibility(const bool )
{
	//TODO run a scenegraph operation
	std::cout << " void TensorFieldWindow::setNodeRestrictionsVisibility(const bool )" << std::endl;
}


void 
TensorFieldWindow::setGhostSurfacesVisibility(const bool )
{
}


void 
TensorFieldWindow::setAnalysisResult(fem::AnalysisResult<double> &result)
{
	this->m_result = &result;
	this->setGradientValuesRange(result);
	this->viewport->setAnalysisResult(result);
}


void 
TensorFieldWindow::connectSignalsToSlots()
{
	WindowWithScaling::connectSignalsToSlots();

	connect(actionMenuVisibility,	SIGNAL(toggled(bool)),	this,	SLOT(toggleMenuBarVisibility(bool) ) );
	connect(actionSetTensionRanges,	SIGNAL(triggered()),	this,	SLOT(setResultsRanges()));
}


void 
TensorFieldWindow::createToolBars(fem::Project &project)
{
	WindowWithScaling::createToolbar(project);
	WindowWithResults::createToolbar(project);

	// create
	toggleMenuBarVisibilityToolBar = addToolBar(tr("Menu bar visibility"));
	toggleMenuBarVisibilityToolBar->addAction(actionMenuVisibility);
}


void 
TensorFieldWindow::setGradientValuesRange(const fem::AnalysisResult<double> &result)
{
	//TODO finish this
	this->m_results_ranges = result.ranges;
}


void 
TensorFieldWindow::toggleMenuBarVisibility(bool visibility)
{
	qWarning("void TensorFieldWindow::toggleMenuBarVisibility(bool visibility) ");
	this->menuBar()->setVisible(visibility);
}


void 
TensorFieldWindow::setResultsRanges()
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
TensorFieldWindow::setSelection(Selection)
{
}


void 
TensorFieldWindow::clearSelection()
{
}


void 
TensorFieldWindow::connectToSelectionManager(SelectionManager &selection_manager)
{
	// connects signals to slots
	std::cout << "void TensorFieldWindow::connectToSelectionManager(SelectionManager &selection_manager)" << std::endl;

	selection_manager.selection_changed.connect( sigc::mem_fun(this, & TensorFieldWindow::setSelection));
	this->selection_changed.connect( sigc::mem_fun(selection_manager, &SelectionManager::setSelection));
}

