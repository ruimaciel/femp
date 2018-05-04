#include "NodeActionsDialog.h++"

#include "LoadPatternDialog.h++"


NodeActionsDialog::NodeActionsDialog(LoadPatternsModel &model, QWidget *parent)
	: QDialog(parent)
{
	setupUi(this);

	this->comboBoxLoadPattern->setModel(&model);

	connect(toolButtonNewLoadPattern,	SIGNAL(clicked()), 	this,	SLOT(handleNewLabelButton()));
}


size_t
NodeActionsDialog::getLoadPattern()
{
	//TODO must get some sort of sanity check
	return this->comboBoxLoadPattern->currentIndex();
}


fem::Point
NodeActionsDialog::getForce()
{
	fem::Point p;
	p.data[0] = this->doubleSpinBoxFx->value();
	p.data[1] = this->doubleSpinBoxFy->value();
	p.data[2] = this->doubleSpinBoxFz->value();
	return p;
}


fem::Point
NodeActionsDialog::getDisplacement()
{
	fem::Point p;
	p.data[0] = this->doubleSpinBoxDx->value();
	p.data[1] = this->doubleSpinBoxDy->value();
	p.data[2] = this->doubleSpinBoxDz->value();
	return p;
}


void
NodeActionsDialog::loadPatternCreated(size_t, fem::LoadPattern const &)
{
	this->comboBoxLoadPattern->view()->reset();
}


void
NodeActionsDialog::handleNewLabelButton()
{
	LoadPatternDialog dialog(this);
	if(dialog.exec() == QDialog::Accepted)
	{
		std::string text;
		text = dialog.getLabel();

		// emit signal
		create_load_pattern(text);
	}
}

