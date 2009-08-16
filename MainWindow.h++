#include <QMainWindow>

#include "ui/ui_MainWindow.h"

#include "CommandLineDockWidget.h++"


class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow (QWidget *parent = 0);

private:
	Ui::MainWindow ui;

	CommandLineDockWidget *commandLineDockWidget;
};

