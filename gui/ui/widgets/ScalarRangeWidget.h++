#ifndef SCALAR_RANGE_WIDGET_HPP
#define SCALAR_RANGE_WIDGET_HPP

#include <sigc++/sigc++.h> 	// to side step a compiler error caused by a conflict with Qt and libsigc++
#include <QWidget>
#include <QString>

#include "ui_ScalarRangeWidget.h"


/**
Widget intended to be used to specify the range of a given parameter
**/
class ScalarRangeWidget
	: public QWidget
{
	Q_OBJECT

private:
	Ui::ScalarRangeWidget ui;

public:
	ScalarRangeWidget(const QString label, QWidget *parent = NULL);

	bool getMaximum(double &) const;
	bool getMinimum(double &) const;


protected:
	void connectSignalsToSlots();


public Q_SLOTS:
	void setLabel(const QString );
	void setMaximum(const double);
	void setMinimum(const double);


protected Q_SLOTS:
	/**
	Emits valuesChanged()
	**/
	void change();

Q_SIGNALS:
	/*
	Signals that the values have changed
	@param	max
	@param 	min
	*/
	void valuesChanged(double, double);
};

#endif

