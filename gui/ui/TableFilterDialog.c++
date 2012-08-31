#include "TableFilterDialog.h++"


TableFilterDialog::TableFilterDialog(QWidget *parent )
	: QDialog(parent)
{
	setupUi(this);

	// set signals and slots
	connect (	checkBoxElements,		SIGNAL(clicked(bool)),	this,	SLOT( toggleElementsCheckboxes(bool)) );
	connect (	checkBoxElementReference,	SIGNAL(clicked(bool)),	this,	SLOT( toggleElementCheckbox(bool)) );
	connect (	checkBoxElementType,		SIGNAL(clicked(bool)),	this,	SLOT( toggleElementCheckbox(bool)) );

	connect (	checkBoxNodeReferences,		SIGNAL(clicked(bool)),	this,	SLOT( toggleNodeReferencesCheckboxes(bool)) );
	connect (	checkBoxNodeGlobalReference,	SIGNAL(clicked(bool)),	this,	SLOT( toggleNodeReferenceCheckbox(bool)) );
	connect (	checkBoxNodeLocalReference,	SIGNAL(clicked(bool)),	this,	SLOT( toggleNodeReferenceCheckbox(bool)) );

	connect (	checkBoxNodePositions,		SIGNAL(clicked(bool)),	this,	SLOT( toggleNodePositionsCheckboxes(bool)) );
	connect (	checkBoxNodePositionX,		SIGNAL(clicked(bool)),	this,	SLOT( toggleNodePositionCheckbox(bool)) );
	connect (	checkBoxNodePositionY,		SIGNAL(clicked(bool)),	this,	SLOT( toggleNodePositionCheckbox(bool)) );
	connect (	checkBoxNodePositionZ,		SIGNAL(clicked(bool)),	this,	SLOT( toggleNodePositionCheckbox(bool)) );

	connect (	checkBoxNodeDisplacements,	SIGNAL(clicked(bool)),	this,	SLOT( toggleNodeDisplacementsCheckboxes(bool)) );
	connect (	checkBoxNodeDisplacementsX,	SIGNAL(clicked(bool)),	this,	SLOT( toggleNodeDisplacementsCheckbox(bool)) );
	connect (	checkBoxNodeDisplacementsY,	SIGNAL(clicked(bool)),	this,	SLOT( toggleNodeDisplacementsCheckbox(bool)) );
	connect (	checkBoxNodeDisplacementsZ,	SIGNAL(clicked(bool)),	this,	SLOT( toggleNodeDisplacementsCheckbox(bool)) );

	connect (	checkBoxStrains,	SIGNAL(clicked(bool)),	this,	SLOT( toggleStrainsCheckboxes(bool)) );
	connect (	checkBoxE11,		SIGNAL(clicked(bool)),	this,	SLOT( toggleStrainsCheckbox(bool)) );
	connect (	checkBoxE22,		SIGNAL(clicked(bool)),	this,	SLOT( toggleStrainsCheckbox(bool)) );
	connect (	checkBoxE33,		SIGNAL(clicked(bool)),	this,	SLOT( toggleStrainsCheckbox(bool)) );
	connect (	checkBoxE12,		SIGNAL(clicked(bool)),	this,	SLOT( toggleStrainsCheckbox(bool)) );
	connect (	checkBoxE23,		SIGNAL(clicked(bool)),	this,	SLOT( toggleStrainsCheckbox(bool)) );
	connect (	checkBoxE13,		SIGNAL(clicked(bool)),	this,	SLOT( toggleStrainsCheckbox(bool)) );

	connect (	checkBoxStresses,	SIGNAL(clicked(bool)),	this,	SLOT( toggleStressesCheckboxes(bool)) );
	connect (	checkBoxS11,		SIGNAL(clicked(bool)),	this,	SLOT( toggleStressesCheckbox(bool)) );
	connect (	checkBoxS22,		SIGNAL(clicked(bool)),	this,	SLOT( toggleStressesCheckbox(bool)) );
	connect (	checkBoxS33,		SIGNAL(clicked(bool)),	this,	SLOT( toggleStressesCheckbox(bool)) );
	connect (	checkBoxS12,		SIGNAL(clicked(bool)),	this,	SLOT( toggleStressesCheckbox(bool)) );
	connect (	checkBoxS23,		SIGNAL(clicked(bool)),	this,	SLOT( toggleStressesCheckbox(bool)) );
	connect (	checkBoxS13,		SIGNAL(clicked(bool)),	this,	SLOT( toggleStressesCheckbox(bool)) );
}


void 
TableFilterDialog::toggleElementsCheckboxes(bool state)
{
	this->checkBoxElementReference->setChecked(state);
	this->checkBoxElementType->setChecked(state);
}


void 
TableFilterDialog::toggleElementCheckbox(bool)
{
	if (checkBoxElementReference->isChecked() && checkBoxElementType->isChecked())
	{
		checkBoxElements->setCheckState(Qt::Checked);
	}
	else if (!checkBoxElementReference->isChecked() && !checkBoxElementType->isChecked())
	{
		checkBoxElements->setCheckState(Qt::Unchecked);
	}
	else
	{
		checkBoxElements->setCheckState(Qt::PartiallyChecked);
	}
}


void 
TableFilterDialog::toggleNodeReferencesCheckboxes(bool state)
{
	this->checkBoxNodeGlobalReference->setChecked(state);
	this->checkBoxNodeLocalReference->setChecked(state);
}


void 
TableFilterDialog::toggleNodeReferenceCheckbox(bool)
{
	if (checkBoxNodeGlobalReference->isChecked() && checkBoxNodeLocalReference->isChecked())
	{
		checkBoxNodeReferences->setCheckState(Qt::Checked);
	}
	else if (!checkBoxNodeGlobalReference->isChecked() && !checkBoxNodeLocalReference->isChecked())
	{
		checkBoxNodeReferences->setCheckState(Qt::Unchecked);
	}
	else
	{
		checkBoxNodeReferences->setCheckState(Qt::PartiallyChecked);
	}
}


void 
TableFilterDialog::toggleNodePositionsCheckboxes(bool state)
{
	this->checkBoxNodePositionX->setChecked(state);
	this->checkBoxNodePositionY->setChecked(state);
	this->checkBoxNodePositionZ->setChecked(state);
}


void 
TableFilterDialog::toggleNodePositionCheckbox(bool)
{
	if (checkBoxNodePositionX->isChecked() && checkBoxNodePositionY->isChecked() && checkBoxNodePositionZ->isChecked())
	{
		checkBoxNodePositions->setCheckState(Qt::Checked);
	}
	else if (!checkBoxNodePositionX->isChecked() && !checkBoxNodePositionY->isChecked() && !checkBoxNodePositionZ->isChecked())
	{
		checkBoxNodePositions->setCheckState(Qt::Unchecked);
	}
	else
	{
		checkBoxNodePositions->setCheckState(Qt::PartiallyChecked);
	}
}


void 
TableFilterDialog::toggleNodeDisplacementsCheckboxes(bool state)
{
	this->checkBoxNodeDisplacementsX->setChecked(state);
	this->checkBoxNodeDisplacementsY->setChecked(state);
	this->checkBoxNodeDisplacementsZ->setChecked(state);
}


void 
TableFilterDialog::toggleNodeDisplacementsCheckbox(bool)
{
	if (checkBoxNodeDisplacementsX->isChecked() && checkBoxNodeDisplacementsY->isChecked() && checkBoxNodeDisplacementsZ->isChecked())
	{
		checkBoxNodeDisplacements->setCheckState(Qt::Checked);
	}
	else if (!checkBoxNodeDisplacementsX->isChecked() && !checkBoxNodeDisplacementsY->isChecked() && !checkBoxNodeDisplacementsZ->isChecked())
	{
		checkBoxNodeDisplacements->setCheckState(Qt::Unchecked);
	}
	else
	{
		checkBoxNodeDisplacements->setCheckState(Qt::PartiallyChecked);
	}
}


void 
TableFilterDialog::toggleStrainsCheckboxes(bool state)
{
	this->checkBoxE11->setChecked(state);
	this->checkBoxE22->setChecked(state);
	this->checkBoxE33->setChecked(state);
	this->checkBoxE12->setChecked(state);
	this->checkBoxE23->setChecked(state);
	this->checkBoxE13->setChecked(state);
}


void 
TableFilterDialog::toggleStrainsCheckbox(bool)
{
	if (checkBoxE11->isChecked() && checkBoxE22->isChecked() && checkBoxE33->isChecked() && checkBoxE12->isChecked() && checkBoxE23->isChecked() && checkBoxE13->isChecked())
	{
		checkBoxStrains->setCheckState(Qt::Checked);
	}
	else if (!checkBoxE11->isChecked() && !checkBoxE22->isChecked() && !checkBoxE33->isChecked() && !checkBoxE12->isChecked() && !checkBoxE23->isChecked() && !checkBoxE13->isChecked())
	{
		checkBoxStrains->setCheckState(Qt::Unchecked);
	}
	else
	{
		checkBoxStrains->setCheckState(Qt::PartiallyChecked);
	}
}


void 
TableFilterDialog::toggleStressesCheckboxes(bool state)
{
	this->checkBoxE11->setChecked(state);
	this->checkBoxE22->setChecked(state);
	this->checkBoxE33->setChecked(state);
	this->checkBoxE12->setChecked(state);
	this->checkBoxE23->setChecked(state);
	this->checkBoxE13->setChecked(state);
}


void 
TableFilterDialog::toggleStressesCheckbox(bool)
{
	if (checkBoxS11->isChecked() && checkBoxS22->isChecked() && checkBoxS33->isChecked() && checkBoxS12->isChecked() && checkBoxS23->isChecked() && checkBoxS13->isChecked())
	{
		checkBoxStresses->setCheckState(Qt::Checked);
	}
	else if (!checkBoxS11->isChecked() && !checkBoxS22->isChecked() && !checkBoxS33->isChecked() && !checkBoxS12->isChecked() && !checkBoxS23->isChecked() && !checkBoxS13->isChecked())
	{
		checkBoxStresses->setCheckState(Qt::Unchecked);
	}
	else
	{
		checkBoxStresses->setCheckState(Qt::PartiallyChecked);
	}
}
