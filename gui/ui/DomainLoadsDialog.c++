#include "DomainLoadsDialog.h++"

#include "LoadPatternDialog.h++"


DomainLoadsDialog::DomainLoadsDialog(LoadPatternsModel &model, QWidget *parent)
	: QDialog(parent)
{
	setupUi(this);

	this->comboBoxLoadPattern->setModel(&model);

	connect(toolButtonNewLoadPattern,	SIGNAL(clicked()), 	this,	SLOT(handleNewLabelButton()));
}


size_t
DomainLoadsDialog::getLoadPattern()
{
	//TODO must get some sort of sanity check
	return this->comboBoxLoadPattern->currentIndex();
}


fem::point
DomainLoadsDialog::getForce()
{
	fem::point p;
	p.data[0] = this->doubleSpinBoxFx->value();
	p.data[1] = this->doubleSpinBoxFy->value();
	p.data[2] = this->doubleSpinBoxFz->value();
	return p;
}


void 
DomainLoadsDialog::loadPatternCreated(size_t, fem::LoadPattern const &)
{
	this->comboBoxLoadPattern->view()->reset();
}


void 
DomainLoadsDialog::handleNewLabelButton()
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

