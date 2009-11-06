#include "CommandLineDockWidget.h++"


CommandLineDockWidget::CommandLineDockWidget(QWidget *parent): QDockWidget("default inherited",parent)
{
	ui.setupUi(this);

	/* connect SIGNALs and SLOTs */
	QObject::connect(ui.commandLineInput, SIGNAL( returnPressed(void)), this, SLOT(commandEntered(void)) );
	QObject::connect(this, SIGNAL( executeCommand(QString)), this, SLOT(standard_output(QString)) );
}


void CommandLineDockWidget::standard_output(const QString &text)
{
	this->ui.commandHistoryLog->appendPlainText(text);
}


void CommandLineDockWidget::standard_error(const QString &text)
{
	/*TODO tweak this in order to differenciate error messages */
	this->ui.commandHistoryLog->appendPlainText(text);
}


void CommandLineDockWidget::commandEntered(void)
{
	Q_EMIT executeCommand(ui.commandLineInput->text() );
	ui.commandLineInput->clear();
}
