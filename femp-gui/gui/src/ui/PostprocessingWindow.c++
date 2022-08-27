#include "PostprocessingWindow.h++"

#include <libfemp/ElementResults/ElementResults.h++>
#include <map>
#include <ui/dialogs/ResultsRangeDialog.h++>

#include "../viewer/PostprocessingViewport.h++"

PostprocessingWindow::PostprocessingWindow(fem::Project& project, fem::AnalysisResult& result, ViewportColors& colors, QWidget* parent)
	: MdiWindow(parent), WindowWithResults(), WindowWithPostprocessing(), WindowWithScaling(), BaseWindow("Gradient") {
	this->setGradientValuesRange(result);
	this->viewport = new PostprocessingViewport(project, result, m_resultsRanges, parent);

	this->setCentralWidget(viewport);

	this->viewport->setColors(colors);

	WindowWithScaling::createMenuBar(this, this->menuBar());

	this->createToolBars(project);

	connectSignalsToSlots();
}

void PostprocessingWindow::setDisplacementsScale(double scale) {
	this->viewport->setDisplacementsScale((float)scale);
	this->viewport->refresh();
}

void PostprocessingWindow::setAnalysisResult(fem::AnalysisResult& result) {
	this->m_result = &result;
	this->setGradientValuesRange(result);
	this->viewport->setAnalysisResult(result);
}

void PostprocessingWindow::connectSignalsToSlots() {
	MdiWindow::connectSignalsToSlots();
	WindowWithScaling::connectSignalsToSlots(this);
	WindowWithPostprocessing::connectSignalsToSlots(this);

	connect(m_postprocessingComboBox, SIGNAL(activated(int)), this, SLOT(setPostprocessingState(int)));
	connect(m_actionMenuVisibility, SIGNAL(toggled(bool)), this, SLOT(toggleMenuBarVisibility(bool)));
	connect(m_actionSetTensionRanges, SIGNAL(triggered()), this, SLOT(setResultsRanges()));
}

void PostprocessingWindow::createToolBars(fem::Project& project) {
	WindowWithScaling::createToolbar(this, project);
	WindowWithResults::createToolbar(this, project);
	WindowWithPostprocessing::createToolbar(this, project);

	// create
	m_toolBarToggleMenuBarVisibility = addToolBar(tr("Menu bar visibility"));
	m_toolBarToggleMenuBarVisibility->addAction(m_actionMenuVisibility);
}

void PostprocessingWindow::setGradientValuesRange(const fem::AnalysisResult& result) {
	this->m_resultsRanges = result.ranges;
}

void PostprocessingWindow::toggleMenuBarVisibility(bool visibility) {
	qWarning("void PostprocessingWindow::toggleMenuBarVisibility(bool visibility) ");
	this->menuBar()->setVisible(visibility);
}

void PostprocessingWindow::setResultsRanges() {
	ResultsRangeDialog dialog(this);
	dialog.setValueRanges(this->m_resultsRanges);

	switch (dialog.exec()) {
		case QDialog::Accepted:
			dialog.getValueRanges(this->m_resultsRanges);
			break;

		default:
			break;
	};
}

void PostprocessingWindow::setPostprocessingState(int state) {
	PostprocessingViewport* current_vp = nullptr;
	current_vp = static_cast<PostprocessingViewport*>(this->viewport);
	if (current_vp == nullptr) {
		return;
	}

	switch (state) {
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

		default:
			qWarning(" PostprocessingWindow::setPostprocessingState(%d), unused state", state);
			break;
	}
}
