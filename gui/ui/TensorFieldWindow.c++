#include "TensorFieldWindow.h++"

#include "../viewer/TensorFieldViewport.h++"

#include <map>
#include <ui/dialogs/ResultsRangeDialog.h++>
#include <libfemp/ElementResults/ElementResults.h++>



TensorFieldWindow::TensorFieldWindow (fem::Project &project, fem::AnalysisResult &result, ViewportColors &colors, QWidget *parent)
	: MdiWindow(parent), 
	WindowWithResults(),
	BaseWindow("Tensor field")
{
	this->setGradientValuesRange(result);

	m_tensor_field_viewport = new TensorFieldViewport(project, result, m_results_ranges,  parent);

	this->viewport = m_tensor_field_viewport;

	this->setCentralWidget(viewport);

	this->viewport->setColors(colors);


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
TensorFieldWindow::setAnalysisResult(fem::AnalysisResult &result)
{
	this->m_result = &result;
	this->setGradientValuesRange(result);
	this->viewport->setAnalysisResult(result);
}


void 
TensorFieldWindow::connectSignalsToSlots()
{
	// nasty hack to connect libsigc++ signal
	MdiWindow::connectSignalsToSlots();
	WindowWithResults::connectSignalsToSlots(this);

	connect(m_actionMenuVisibility,	SIGNAL(toggled(bool)),	this,	SLOT(toggleMenuBarVisibility(bool) ) );
	//connect(actionSetTensionRanges,	SIGNAL(triggered()),	this,	SLOT(setResultsRanges()));
	connect(actionVisibleNegativePrincipalStresses,	SIGNAL(toggled(bool)),	this,	SLOT(setNegativePrincipalStressesVisibility(bool)));
	connect(actionVisiblePositivePrincipalStresses,	SIGNAL(toggled(bool)),	this,	SLOT(setPositivePrincipalStressesVisibility(bool)));
}


void 
TensorFieldWindow::createToolBars(fem::Project &project)
{
	WindowWithResults::createToolbar(this, project);

	// create
	/*
	toggleMenuBarVisibilityToolBar = addToolBar(tr("Menu bar visibility"));
	toggleMenuBarVisibilityToolBar->addAction(actionMenuVisibility);
	*/
	m_tensor_field_visualization = addToolBar(tr("Tensor field visualization"));

	actionVisibleNegativePrincipalStresses = new QAction( tr("Negative"),this);
	actionVisibleNegativePrincipalStresses->setCheckable(true);
	actionVisibleNegativePrincipalStresses->setChecked(true);
	m_tensor_field_visualization->addAction(actionVisibleNegativePrincipalStresses);

	actionVisiblePositivePrincipalStresses = new QAction( tr("Positive"),this);
	actionVisiblePositivePrincipalStresses->setCheckable(true);
	actionVisiblePositivePrincipalStresses->setChecked(true);
	m_tensor_field_visualization->addAction(actionVisiblePositivePrincipalStresses);
}


void 
TensorFieldWindow::setGradientValuesRange(const fem::AnalysisResult &result)
{
	//TODO finish this
	this->m_results_ranges = result.ranges;
}


void 
TensorFieldWindow::toggleMenuBarVisibility(bool visibility)
{
	//TODO replace qWarnings with calls to cerr
	qWarning("void TensorFieldWindow::toggleMenuBarVisibility(bool visibility) ");
	this->menuBar()->setVisible(visibility);
}


void 
TensorFieldWindow::setNegativePrincipalStressesVisibility(const bool state)
{
	std::cerr << "TensorFieldWindow::setNegativePrincipalStressesVisibility(const bool state)" << std::endl;
	
	this->m_tensor_field_viewport->showNegativePrincipalStressesVisibility(state);
	this->viewport->refresh();
}


void 
TensorFieldWindow::setPositivePrincipalStressesVisibility(const bool state)
{
	std::cerr << "TensorFieldWindow::setPositivePrincipalStressesVisibility(const bool state)" << std::endl;
	
	this->m_tensor_field_viewport->showPositivePrincipalStressesVisibility(state);
	this->viewport->refresh();
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

