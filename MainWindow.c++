#include "MainWindow.h++"


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
	ui.setupUi(this);

	commandLineDockWidget = new CommandLineDockWidget(this);
	this->addDockWidget(static_cast<Qt::DockWidgetArea>(8), commandLineDockWidget);
}
