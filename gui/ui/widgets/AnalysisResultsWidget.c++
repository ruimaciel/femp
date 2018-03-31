#include "AnalysisResultsWidget.h++"

#include <iostream>

#include <ui/dialogs/TableFilterDialog.h++>

#include <libfemp/Model.h++>
#include <libfemp/Node.h++>


AnalysisResultsWidget::AnalysisResultsWidget(fem::Project &project, QWidget *parent)
	: QWidget(parent), m_project(project)
{
	setupUi(this);

	// initialize member variables
	setProjectResults(project.result[0]);	//CRUDE HACK

	// set the table model for the model/view stuff
	m_model = new AnalysisResultsModel(project, parent);
	m_proxy_model.setSourceModel(m_model);

	this->tableView->setModel(&m_proxy_model);

	// signals and slots
	connect(this->pushButtonFilters, SIGNAL(clicked() ), this, SLOT( setFilterOptions() ));

}


void 
AnalysisResultsWidget::setProjectResults(fem::AnalysisResult const &results)
{
	m_result  = &results;
}


void 
AnalysisResultsWidget::fillComboBox(fem::Model const &)
{
	//TODO finish this
}

void 
AnalysisResultsWidget::setFilterOptions()
{
	TableFilterDialog dialog(this);

	// set the dialog options 
#define MEMBER_HELPER(NN,XX) dialog.set##XX##Visible(!tableView->isColumnHidden(NN));
	MEMBER_HELPER( 0, ElementReference);
	MEMBER_HELPER( 1, ElementType);
	MEMBER_HELPER( 2, NodeGlobalReference);
	MEMBER_HELPER( 3, NodeLocalReference);
	MEMBER_HELPER( 4, NodePositionX);
	MEMBER_HELPER( 5, NodePositionY);
	MEMBER_HELPER( 6, NodePositionZ);
	MEMBER_HELPER( 7, NodeDisplacementsX);
	MEMBER_HELPER( 8, NodeDisplacementsY);
	MEMBER_HELPER( 9, NodeDisplacementsZ);
	MEMBER_HELPER(10, E11);
	MEMBER_HELPER(11, E22);
	MEMBER_HELPER(12, E33);
	MEMBER_HELPER(13, E12);
	MEMBER_HELPER(14, E23);
	MEMBER_HELPER(15, E13);
	MEMBER_HELPER(16, S11);
	MEMBER_HELPER(17, S22);
	MEMBER_HELPER(18, S33);
	MEMBER_HELPER(19, S12);
	MEMBER_HELPER(20, S23);
	MEMBER_HELPER(21, S13);
	MEMBER_HELPER(22, VonMises);
#undef MEMBER_HELPER

	switch(dialog.exec())
	{
		case QDialog::Accepted:
			// set the new options
#define MEMBER_HELPER(NN,XX) this->tableView->setColumnHidden(NN, !dialog.get##XX##Visible());
			MEMBER_HELPER( 0, ElementReference);
			MEMBER_HELPER( 1, ElementType);
			MEMBER_HELPER( 2, NodeGlobalReference);
			MEMBER_HELPER( 3, NodeLocalReference);
			MEMBER_HELPER( 4, NodePositionX);
			MEMBER_HELPER( 5, NodePositionY);
			MEMBER_HELPER( 6, NodePositionZ);
			MEMBER_HELPER( 7, NodeDisplacementsX);
			MEMBER_HELPER( 8, NodeDisplacementsY);
			MEMBER_HELPER( 9, NodeDisplacementsZ);
			MEMBER_HELPER(10, E11);
			MEMBER_HELPER(11, E22);
			MEMBER_HELPER(12, E33);
			MEMBER_HELPER(13, E12);
			MEMBER_HELPER(14, E23);
			MEMBER_HELPER(15, E13);
			MEMBER_HELPER(16, S11);
			MEMBER_HELPER(17, S22);
			MEMBER_HELPER(18, S33);
			MEMBER_HELPER(19, S12);
			MEMBER_HELPER(20, S23);
			MEMBER_HELPER(21, S13);
			MEMBER_HELPER(22, VonMises);
#undef MEMBER_HELPER
			break;

		default:
			break;
	}

}

