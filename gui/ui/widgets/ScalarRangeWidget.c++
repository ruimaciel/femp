#include "ScalarRangeWidget.h++"

#include <QDoubleValidator>
#include <QString>


ScalarRangeWidget::ScalarRangeWidget(const QString label, QWidget *parent)
	:QWidget(parent)
{
	ui.setupUi(this);
	QDoubleValidator *validator;
	validator = new QDoubleValidator(0.0, 9e9, 5, this);
	ui.lineEditMaxValue->setValidator(validator);
	validator = new QDoubleValidator(-9e9, 0.0, 5, this);
	ui.lineEditMinValue->setValidator(validator);


	connectSignalsToSlots();

	this->setLabel(label);
}


bool 
ScalarRangeWidget::getMaximum(double &maximum) const
{
	QString temp;
	bool result;
	temp = ui.lineEditMaxValue->text();

	maximum = temp.toDouble(&result);

	return result;
}


bool 
ScalarRangeWidget::getMinimum(double &minimum) const
{
	QString temp;
	bool result;
	temp = ui.lineEditMinValue->text();

	minimum = temp.toDouble(&result);

	return result;
}


void 
ScalarRangeWidget::connectSignalsToSlots()
{
	connect(ui.lineEditMaxValue,	SIGNAL(returnPressed()),	this,	SLOT(change()));
	connect(ui.lineEditMinValue,	SIGNAL(returnPressed()),	this,	SLOT(change()));
}


void 
ScalarRangeWidget::setLabel(const QString label)
{
	this->ui.labelValue->setText(label);
}


void 
ScalarRangeWidget::setMaximum(const double new_maximum)
{
	if(new_maximum > 0)
	{
		ui.lineEditMaxValue->setText(QString::number(new_maximum));
	}
}


void 
ScalarRangeWidget::setMinimum(const double new_minimum)
{
	if(new_minimum < 0)
	{
		ui.lineEditMinValue->setText(QString::number(new_minimum));
	}
}


void
ScalarRangeWidget::change()
{
	double max, min;
	getMaximum(max);
	getMinimum(min);

	emit valuesChanged(max,min);
}


