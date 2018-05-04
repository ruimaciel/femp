#include "LoadPatternDialog.h++"



LoadPatternDialog::LoadPatternDialog(QWidget *parent )
	: QDialog(parent)
{
	setupUi(this);
}


std::string
LoadPatternDialog::getLabel() const
{
	std::string text;
	text = this->lineEditLoadPatternName->text().toStdString();

	return text;
}
