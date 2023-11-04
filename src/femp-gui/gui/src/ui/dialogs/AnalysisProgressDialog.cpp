#include "AnalysisProgressDialog.hpp"

#include "ui_AnalysisProgressDialog.h"

AnalysisProgressDialog::AnalysisProgressDialog(QWidget* parent) : QDialog(parent), m_ui(std::make_unique<Ui::AnalysisProgressDialog>()) {
	m_ui->setupUi(this);
}

AnalysisProgressDialog::~AnalysisProgressDialog() = default;

void AnalysisProgressDialog::beginSection(std::string section_name) {
	timer.start();

	m_section_name = section_name;
	QString temp = QString("started %1)").arg(QString::fromStdString(m_section_name));
	m_ui->textEdit->append(temp);
}

void AnalysisProgressDialog::setProgress(size_t progress) {
	// TODO finish this
	QString temp;
	temp.setNum(progress);
	m_ui->textEdit->append(temp);
}

void AnalysisProgressDialog::endSection() {
	QString temp;
	temp = "finished ";
	temp += m_section_name.c_str();
	temp += "\ttime elapsed: ";
	temp += QString::number(timer.elapsed() / 1000.0);
	temp += " seconds";
	m_ui->textEdit->append(temp);
	m_section_name.clear();
}

void AnalysisProgressDialog::setMessage(const std::string& message) {
	QString temp = QString("%1: %2").arg(QString::fromStdString(m_section_name), QString::fromStdString(message));
	m_ui->textEdit->append(temp);
}

void AnalysisProgressDialog::setError(std::string error_message) {
	m_ui->textEdit->setTextColor(QColor::fromRgb(255, 0, 0));

	QString temp = QString("Error: %1").arg(QString::fromStdString(error_message));
	m_ui->textEdit->append(temp);

	QColor current = m_ui->textEdit->textColor();
	m_ui->textEdit->setTextColor(current);
}

void AnalysisProgressDialog::finish() {
	QString temp = QString("finished processing the model.");
	m_ui->textEdit->append(temp);

	m_ui->buttonBox->setStandardButtons(QDialogButtonBox::Ok);
}
