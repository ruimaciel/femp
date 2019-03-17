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

	m_viewportTensorField = new TensorFieldViewport(project, result, m_resultsRanges,  parent);

	this->viewport = m_viewportTensorField;

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
	connect(m_actionVisibleNegativePrincipalStresses,	SIGNAL(toggled(bool)),	this,	SLOT(setNegativePrincipalStressesVisibility(bool)));
	connect(m_actionVisiblePositivePrincipalStresses,	SIGNAL(toggled(bool)),	this,	SLOT(setPositivePrincipalStressesVisibility(bool)));
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
	m_tensorFieldVisualization = addToolBar(tr("Tensor field visualization"));

	m_actionVisibleNegativePrincipalStresses = new QAction( tr("Negative"),this);
	m_actionVisibleNegativePrincipalStresses->setCheckable(true);
	m_actionVisibleNegativePrincipalStresses->setChecked(true);
	m_tensorFieldVisualization->addAction(m_actionVisibleNegativePrincipalStresses);

	m_actionVisiblePositivePrincipalStresses = new QAction( tr("Positive"),this);
	m_actionVisiblePositivePrincipalStresses->setCheckable(true);
	m_actionVisiblePositivePrincipalStresses->setChecked(true);
	m_tensorFieldVisualization->addAction(m_actionVisiblePositivePrincipalStresses);
}


void
TensorFieldWindow::setGradientValuesRange(const fem::AnalysisResult &result)
{
	//TODO finish this
	this->m_resultsRanges = result.ranges;
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

	this->m_viewportTensorField->showNegativePrincipalStressesVisibility(state);
	this->viewport->refresh();
}


void
TensorFieldWindow::setPositivePrincipalStressesVisibility(const bool state)
{
	std::cerr << "TensorFieldWindow::setPositivePrincipalStressesVisibility(const bool state)" << std::endl;

	this->m_viewportTensorField->showPositivePrincipalStressesVisibility(state);
	this->viewport->refresh();
}


void
TensorFieldWindow::setResultsRanges()
{
	ResultsRangeDialog dialog(this);
	dialog.setValueRanges(this->m_resultsRanges);

	switch(dialog.exec())
	{
	case QDialog::Accepted:
		dialog.getValueRanges(this->m_resultsRanges);
		break;

	default:
		break;
	};
}

