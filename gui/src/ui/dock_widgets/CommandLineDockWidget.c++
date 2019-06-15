#include "CommandLineDockWidget.h++"

CommandLineDockWidget::CommandLineDockWidget(QWidget* parent)
    : QDockWidget("default inherited", parent)
{
    ui.setupUi(this);

    /* connect SIGNALs and SLOTs */
    QObject::connect(ui.commandLineInput, SIGNAL(returnPressed(void)), this, SLOT(commandEntered(void)));
    QObject::connect(this, SIGNAL(executeCommand(QString)), this, SLOT(standard_output(QString)));
}

void CommandLineDockWidget::standard_output(const QString& text)
{
    this->ui.commandHistoryLog->appendPlainText(text);
}

void CommandLineDockWidget::standard_error(const QString& text)
{
    this->ui.commandHistoryLog->appendPlainText(text);
}

void CommandLineDockWidget::getMessage(QString message)
{
    this->ui.commandHistoryLog->appendPlainText(message);
}

void CommandLineDockWidget::getWarning(QString message)
{
    this->ui.commandHistoryLog->appendPlainText("Warning: " + message);
}

void CommandLineDockWidget::getError(QString message)
{
    this->ui.commandHistoryLog->appendPlainText("Error: " + message);
}

void CommandLineDockWidget::clear()
{
    this->ui.commandHistoryLog->clear();
}

void CommandLineDockWidget::commandEntered(void)
{
    Q_EMIT executeCommand(ui.commandLineInput->text());
    ui.commandLineInput->clear();
}
