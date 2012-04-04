#include "AnalysisProgressDialog.h++"

//#include <QtGui/QTextEdit>


AnalysisProgressDialog::AnalysisProgressDialog( QWidget *parent)
	: QDialog(parent)
{
	setupUi(this);
}


void AnalysisProgressDialog::beginSection(std::string section_name)
{
	timer.start();

	QString temp;
	m_section_name = section_name;
	temp = "started ";
	temp += m_section_name.c_str();
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
	temp += QString::number(timer.elapsed()/1000.0 );
	temp += " seconds";
	this->textEdit->append(temp);
	m_section_name.clear();
}


void AnalysisProgressDialog::setMessage(std::string message)
{
	QString temp;
	temp += m_section_name.c_str();
	temp += ": ";
	temp += message.c_str();
	this->textEdit->append(temp);
}

void AnalysisProgressDialog::setError(std::string error_message)
{
	QColor current, error;

	current = this->textEdit->textColor();
	error.setRed(255);
	error.setGreen(0);
	error.setBlue(0);

	this->textEdit->setTextColor(error);
	QString temp;
	temp = "Error: ";
	temp += error_message.c_str();
	this->textEdit->append(temp);
	this->textEdit->setTextColor(current);
}


void AnalysisProgressDialog::finish()
{
	//TODO finish this
	QString temp;
	temp = "finished processing the model ";
	this->textEdit->append(temp);

	this->buttonBox->setStandardButtons(QDialogButtonBox::Ok);
}

