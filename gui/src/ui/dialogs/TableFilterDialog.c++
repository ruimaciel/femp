#include "TableFilterDialog.h++"


TableFilterDialog::TableFilterDialog(QWidget *parent )
	: QDialog(parent)
{
	setupUi(this);

	// set signals and slots
	connect(	checkBoxElements,				&QCheckBox::clicked,	this,	&TableFilterDialog::toggleElementsCheckboxes);
	connect(	checkBoxElementReference,		&QCheckBox::clicked,	this,	&TableFilterDialog::toggleElementCheckbox);
	connect(	checkBoxElementType,			&QCheckBox::clicked,	this,	&TableFilterDialog::toggleElementCheckbox);

	connect(	checkBoxNodeReferences,			&QCheckBox::clicked,	this,	&TableFilterDialog::toggleNodeReferencesCheckboxes);
	connect(	checkBoxNodeGlobalReference,	&QCheckBox::clicked,	this,	&TableFilterDialog::toggleNodeReferenceCheckbox);
	connect(	checkBoxNodeLocalReference,		&QCheckBox::clicked,	this,	&TableFilterDialog::toggleNodeReferenceCheckbox);

	connect(	checkBoxNodePositions,			&QCheckBox::clicked,	this,	&TableFilterDialog::toggleNodePositionsCheckboxes);
	connect(	checkBoxNodePositionX,			&QCheckBox::clicked,	this,	&TableFilterDialog::toggleNodePositionCheckbox);
	connect(	checkBoxNodePositionY,			&QCheckBox::clicked,	this,	&TableFilterDialog::toggleNodePositionCheckbox);
	connect(	checkBoxNodePositionZ,			&QCheckBox::clicked,	this,	&TableFilterDialog::toggleNodePositionCheckbox);

	connect(	checkBoxNodeDisplacements,		&QCheckBox::clicked,	this,	&TableFilterDialog::toggleNodeDisplacementsCheckboxes);
	connect(	checkBoxNodeDisplacementsX,		&QCheckBox::clicked,	this,	&TableFilterDialog::toggleNodeDisplacementsCheckbox);
	connect(	checkBoxNodeDisplacementsY,		&QCheckBox::clicked,	this,	&TableFilterDialog::toggleNodeDisplacementsCheckbox);
	connect(	checkBoxNodeDisplacementsZ,		&QCheckBox::clicked,	this,	&TableFilterDialog::toggleNodeDisplacementsCheckbox);

	connect(	checkBoxStrains,				&QCheckBox::clicked,	this,	&TableFilterDialog::toggleStrainsCheckboxes);
	connect(	checkBoxE11,					&QCheckBox::clicked,	this,	&TableFilterDialog::toggleStrainsCheckbox);
	connect(	checkBoxE22,					&QCheckBox::clicked,	this,	&TableFilterDialog::toggleStrainsCheckbox);
	connect(	checkBoxE33,					&QCheckBox::clicked,	this,	&TableFilterDialog::toggleStrainsCheckbox);
	connect(	checkBoxE12,					&QCheckBox::clicked,	this,	&TableFilterDialog::toggleStrainsCheckbox);
	connect(	checkBoxE23,					&QCheckBox::clicked,	this,	&TableFilterDialog::toggleStrainsCheckbox);
	connect(	checkBoxE13,					&QCheckBox::clicked,	this,	&TableFilterDialog::toggleStrainsCheckbox);

	connect(	checkBoxStresses,				&QCheckBox::clicked,	this,	&TableFilterDialog::toggleStressesCheckboxes);
	connect(	checkBoxS11,					&QCheckBox::clicked,	this,	&TableFilterDialog::toggleStressesCheckbox);
	connect(	checkBoxS22,					&QCheckBox::clicked,	this,	&TableFilterDialog::toggleStressesCheckbox);
	connect(	checkBoxS33,					&QCheckBox::clicked,	this,	&TableFilterDialog::toggleStressesCheckbox);
	connect(	checkBoxS12,					&QCheckBox::clicked,	this,	&TableFilterDialog::toggleStressesCheckbox);
	connect(	checkBoxS23,					&QCheckBox::clicked,	this,	&TableFilterDialog::toggleStressesCheckbox);
	connect(	checkBoxS13,					&QCheckBox::clicked,	this,	&TableFilterDialog::toggleStressesCheckbox);
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
	this->checkBoxS11->setChecked(state);
	this->checkBoxS22->setChecked(state);
	this->checkBoxS33->setChecked(state);
	this->checkBoxS12->setChecked(state);
	this->checkBoxS23->setChecked(state);
	this->checkBoxS13->setChecked(state);
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
