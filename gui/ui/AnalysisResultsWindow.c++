#include "AnalysisResultsWindow.h++"


AnalysisResultsWindow::AnalysisResultsWindow(fem::Project &project, QWidget *parent)
	: QMdiSubWindow(parent), BaseWindow("Analysis results")
{
	m_project = &project;
	m_analysis_results_widget = new AnalysisResultsWidget(project, parent);

	this->setAttribute(Qt::WA_DeleteOnClose);
	this->setWindowTitle(tr("Analysis results"));
	this->setWidget(m_analysis_results_widget);
}


