#include "TableFilterDialog.h++"

#include "ui_TableFilterDialog.h"

TableFilterDialog::TableFilterDialog(QWidget* parent) : QDialog(parent), m_ui(std::make_unique<Ui::TableFilterDialog>()) {
	m_ui->setupUi(this);

	// set signals and slots
	connect(m_ui->checkBoxElements, &QCheckBox::clicked, this, &TableFilterDialog::toggleElementsCheckboxes);
	connect(m_ui->checkBoxElementReference, &QCheckBox::clicked, this, &TableFilterDialog::toggleElementCheckbox);
	connect(m_ui->checkBoxElementType, &QCheckBox::clicked, this, &TableFilterDialog::toggleElementCheckbox);

	connect(m_ui->checkBoxNodeReferences, &QCheckBox::clicked, this, &TableFilterDialog::toggleNodeReferencesCheckboxes);
	connect(m_ui->checkBoxNodeGlobalReference, &QCheckBox::clicked, this, &TableFilterDialog::toggleNodeReferenceCheckbox);
	connect(m_ui->checkBoxNodeLocalReference, &QCheckBox::clicked, this, &TableFilterDialog::toggleNodeReferenceCheckbox);

	connect(m_ui->checkBoxNodePositions, &QCheckBox::clicked, this, &TableFilterDialog::toggleNodePositionsCheckboxes);
	connect(m_ui->checkBoxNodePositionX, &QCheckBox::clicked, this, &TableFilterDialog::toggleNodePositionCheckbox);
	connect(m_ui->checkBoxNodePositionY, &QCheckBox::clicked, this, &TableFilterDialog::toggleNodePositionCheckbox);
	connect(m_ui->checkBoxNodePositionZ, &QCheckBox::clicked, this, &TableFilterDialog::toggleNodePositionCheckbox);

	connect(m_ui->checkBoxNodeDisplacements, &QCheckBox::clicked, this, &TableFilterDialog::toggleNodeDisplacementsCheckboxes);
	connect(m_ui->checkBoxNodeDisplacementsX, &QCheckBox::clicked, this, &TableFilterDialog::toggleNodeDisplacementsCheckbox);
	connect(m_ui->checkBoxNodeDisplacementsY, &QCheckBox::clicked, this, &TableFilterDialog::toggleNodeDisplacementsCheckbox);
	connect(m_ui->checkBoxNodeDisplacementsZ, &QCheckBox::clicked, this, &TableFilterDialog::toggleNodeDisplacementsCheckbox);

	connect(m_ui->checkBoxStrains, &QCheckBox::clicked, this, &TableFilterDialog::toggleStrainsCheckboxes);
	connect(m_ui->checkBoxE11, &QCheckBox::clicked, this, &TableFilterDialog::toggleStrainsCheckbox);
	connect(m_ui->checkBoxE22, &QCheckBox::clicked, this, &TableFilterDialog::toggleStrainsCheckbox);
	connect(m_ui->checkBoxE33, &QCheckBox::clicked, this, &TableFilterDialog::toggleStrainsCheckbox);
	connect(m_ui->checkBoxE12, &QCheckBox::clicked, this, &TableFilterDialog::toggleStrainsCheckbox);
	connect(m_ui->checkBoxE23, &QCheckBox::clicked, this, &TableFilterDialog::toggleStrainsCheckbox);
	connect(m_ui->checkBoxE13, &QCheckBox::clicked, this, &TableFilterDialog::toggleStrainsCheckbox);

	connect(m_ui->checkBoxStresses, &QCheckBox::clicked, this, &TableFilterDialog::toggleStressesCheckboxes);
	connect(m_ui->checkBoxS11, &QCheckBox::clicked, this, &TableFilterDialog::toggleStressesCheckbox);
	connect(m_ui->checkBoxS22, &QCheckBox::clicked, this, &TableFilterDialog::toggleStressesCheckbox);
	connect(m_ui->checkBoxS33, &QCheckBox::clicked, this, &TableFilterDialog::toggleStressesCheckbox);
	connect(m_ui->checkBoxS12, &QCheckBox::clicked, this, &TableFilterDialog::toggleStressesCheckbox);
	connect(m_ui->checkBoxS23, &QCheckBox::clicked, this, &TableFilterDialog::toggleStressesCheckbox);
	connect(m_ui->checkBoxS13, &QCheckBox::clicked, this, &TableFilterDialog::toggleStressesCheckbox);
}

TableFilterDialog::~TableFilterDialog() = default;

#define MEMBER_HELPER(XX)                                  \
	void TableFilterDialog::set##XX##Visible(bool state) { \
		m_ui->checkBox##XX->setChecked(state);             \
	}                                                      \
	bool TableFilterDialog::get##XX##Visible() const {     \
		return m_ui->checkBox##XX->isChecked();            \
	}
MEMBER_HELPER(ElementReference);
MEMBER_HELPER(ElementType);
MEMBER_HELPER(NodeGlobalReference);
MEMBER_HELPER(NodeLocalReference);
MEMBER_HELPER(NodePositionX);
MEMBER_HELPER(NodePositionY);
MEMBER_HELPER(NodePositionZ);
MEMBER_HELPER(NodeDisplacementsX);
MEMBER_HELPER(NodeDisplacementsY);
MEMBER_HELPER(NodeDisplacementsZ);
MEMBER_HELPER(E11);
MEMBER_HELPER(E22);
MEMBER_HELPER(E33);
MEMBER_HELPER(E12);
MEMBER_HELPER(E23);
MEMBER_HELPER(E13);
MEMBER_HELPER(S11);
MEMBER_HELPER(S22);
MEMBER_HELPER(S33);
MEMBER_HELPER(S12);
MEMBER_HELPER(S23);
MEMBER_HELPER(S13);
MEMBER_HELPER(VonMises);
#undef MEMBER_HELPER

void TableFilterDialog::toggleElementsCheckboxes(bool state) {
	m_ui->checkBoxElementReference->setChecked(state);
	m_ui->checkBoxElementType->setChecked(state);
}

void TableFilterDialog::toggleElementCheckbox(bool) {
	if (m_ui->checkBoxElementReference->isChecked() && m_ui->checkBoxElementType->isChecked()) {
		m_ui->checkBoxElements->setCheckState(Qt::Checked);
	} else if (!m_ui->checkBoxElementReference->isChecked() && !m_ui->checkBoxElementType->isChecked()) {
		m_ui->checkBoxElements->setCheckState(Qt::Unchecked);
	} else {
		m_ui->checkBoxElements->setCheckState(Qt::PartiallyChecked);
	}
}

void TableFilterDialog::toggleNodeReferencesCheckboxes(bool state) {
	m_ui->checkBoxNodeGlobalReference->setChecked(state);
	m_ui->checkBoxNodeLocalReference->setChecked(state);
}

void TableFilterDialog::toggleNodeReferenceCheckbox(bool) {
	if (m_ui->checkBoxNodeGlobalReference->isChecked() && m_ui->checkBoxNodeLocalReference->isChecked()) {
		m_ui->checkBoxNodeReferences->setCheckState(Qt::Checked);
	} else if (!m_ui->checkBoxNodeGlobalReference->isChecked() && !m_ui->checkBoxNodeLocalReference->isChecked()) {
		m_ui->checkBoxNodeReferences->setCheckState(Qt::Unchecked);
	} else {
		m_ui->checkBoxNodeReferences->setCheckState(Qt::PartiallyChecked);
	}
}

void TableFilterDialog::toggleNodePositionsCheckboxes(bool state) {
	m_ui->checkBoxNodePositionX->setChecked(state);
	m_ui->checkBoxNodePositionY->setChecked(state);
	m_ui->checkBoxNodePositionZ->setChecked(state);
}

void TableFilterDialog::toggleNodePositionCheckbox(bool) {
	if (m_ui->checkBoxNodePositionX->isChecked() && m_ui->checkBoxNodePositionY->isChecked() && m_ui->checkBoxNodePositionZ->isChecked()) {
		m_ui->checkBoxNodePositions->setCheckState(Qt::Checked);
	} else if (!m_ui->checkBoxNodePositionX->isChecked() && !m_ui->checkBoxNodePositionY->isChecked() && !m_ui->checkBoxNodePositionZ->isChecked()) {
		m_ui->checkBoxNodePositions->setCheckState(Qt::Unchecked);
	} else {
		m_ui->checkBoxNodePositions->setCheckState(Qt::PartiallyChecked);
	}
}

void TableFilterDialog::toggleNodeDisplacementsCheckboxes(bool state) {
	m_ui->checkBoxNodeDisplacementsX->setChecked(state);
	m_ui->checkBoxNodeDisplacementsY->setChecked(state);
	m_ui->checkBoxNodeDisplacementsZ->setChecked(state);
}

void TableFilterDialog::toggleNodeDisplacementsCheckbox(bool) {
	if (m_ui->checkBoxNodeDisplacementsX->isChecked() && m_ui->checkBoxNodeDisplacementsY->isChecked() && m_ui->checkBoxNodeDisplacementsZ->isChecked()) {
		m_ui->checkBoxNodeDisplacements->setCheckState(Qt::Checked);
	} else if (!m_ui->checkBoxNodeDisplacementsX->isChecked() && !m_ui->checkBoxNodeDisplacementsY->isChecked() &&
			   !m_ui->checkBoxNodeDisplacementsZ->isChecked()) {
		m_ui->checkBoxNodeDisplacements->setCheckState(Qt::Unchecked);
	} else {
		m_ui->checkBoxNodeDisplacements->setCheckState(Qt::PartiallyChecked);
	}
}

void TableFilterDialog::toggleStrainsCheckboxes(bool state) {
	m_ui->checkBoxE11->setChecked(state);
	m_ui->checkBoxE22->setChecked(state);
	m_ui->checkBoxE33->setChecked(state);
	m_ui->checkBoxE12->setChecked(state);
	m_ui->checkBoxE23->setChecked(state);
	m_ui->checkBoxE13->setChecked(state);
}

void TableFilterDialog::toggleStrainsCheckbox(bool) {
	if (m_ui->checkBoxE11->isChecked() && m_ui->checkBoxE22->isChecked() && m_ui->checkBoxE33->isChecked() && m_ui->checkBoxE12->isChecked() &&
		m_ui->checkBoxE23->isChecked() && m_ui->checkBoxE13->isChecked()) {
		m_ui->checkBoxStrains->setCheckState(Qt::Checked);
	} else if (!m_ui->checkBoxE11->isChecked() && !m_ui->checkBoxE22->isChecked() && !m_ui->checkBoxE33->isChecked() && !m_ui->checkBoxE12->isChecked() &&
			   !m_ui->checkBoxE23->isChecked() && !m_ui->checkBoxE13->isChecked()) {
		m_ui->checkBoxStrains->setCheckState(Qt::Unchecked);
	} else {
		m_ui->checkBoxStrains->setCheckState(Qt::PartiallyChecked);
	}
}

void TableFilterDialog::toggleStressesCheckboxes(bool state) {
	m_ui->checkBoxS11->setChecked(state);
	m_ui->checkBoxS22->setChecked(state);
	m_ui->checkBoxS33->setChecked(state);
	m_ui->checkBoxS12->setChecked(state);
	m_ui->checkBoxS23->setChecked(state);
	m_ui->checkBoxS13->setChecked(state);
}

void TableFilterDialog::toggleStressesCheckbox(bool) {
	if (m_ui->checkBoxS11->isChecked() && m_ui->checkBoxS22->isChecked() && m_ui->checkBoxS33->isChecked() && m_ui->checkBoxS12->isChecked() &&
		m_ui->checkBoxS23->isChecked() && m_ui->checkBoxS13->isChecked()) {
		m_ui->checkBoxStresses->setCheckState(Qt::Checked);
	} else if (!m_ui->checkBoxS11->isChecked() && !m_ui->checkBoxS22->isChecked() && !m_ui->checkBoxS33->isChecked() && !m_ui->checkBoxS12->isChecked() &&
			   !m_ui->checkBoxS23->isChecked() && !m_ui->checkBoxS13->isChecked()) {
		m_ui->checkBoxStresses->setCheckState(Qt::Unchecked);
	} else {
		m_ui->checkBoxStresses->setCheckState(Qt::PartiallyChecked);
	}
}
