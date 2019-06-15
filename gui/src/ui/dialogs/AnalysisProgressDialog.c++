#include "AnalysisProgressDialog.h++"

AnalysisProgressDialog::AnalysisProgressDialog(QWidget* parent)
    : QDialog(parent)
{
    setupUi(this);
}

void AnalysisProgressDialog::beginSection(std::string section_name)
{
    timer.start();

    m_section_name = section_name;
    QString temp = QString("started %1)").arg(QString::fromStdString(m_section_name));
    this->textEdit->append(temp);
}

void AnalysisProgressDialog::setProgress(size_t progress)
{
    //TODO finish this
    QString temp;
    temp.setNum(progress);
    this->textEdit->append(temp);
}

void AnalysisProgressDialog::endSection()
{
    QString temp;
    temp = "finished ";
    temp += m_section_name.c_str();
    temp += "\ttime elapsed: ";
    temp += QString::number(timer.elapsed() / 1000.0);
    temp += " seconds";
    this->textEdit->append(temp);
    m_section_name.clear();
}

void AnalysisProgressDialog::setMessage(const std::string& message)
{
    QString temp = QString("%1: %2").arg(QString::fromStdString(m_section_name), QString::fromStdString(message));
    this->textEdit->append(temp);
}

void AnalysisProgressDialog::setError(std::string error_message)
{
    this->textEdit->setTextColor(QColor::fromRgb(255, 0, 0));

    QString temp = QString("Error: %1").arg(QString::fromStdString(error_message));
    this->textEdit->append(temp);

    QColor current = this->textEdit->textColor();
    this->textEdit->setTextColor(current);
}

void AnalysisProgressDialog::finish()
{
    QString temp = QString("finished processing the model %1").arg(temp);
    this->textEdit->append(temp);

    this->buttonBox->setStandardButtons(QDialogButtonBox::Ok);
}
