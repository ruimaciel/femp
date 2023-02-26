#include "LoadPatternDialog.h++"

#include "ui_LoadPatternDialog.h"

LoadPatternDialog::LoadPatternDialog(QWidget* parent) : QDialog(parent), m_ui(std::unique_ptr<Ui::LoadPatternDialog>()) {
	m_ui->setupUi(this);
}

LoadPatternDialog::~LoadPatternDialog() = default;

std::string LoadPatternDialog::getLabel() const {
	std::string text;
	text = m_ui->lineEditLoadPatternName->text().toStdString();

	return text;
}
