#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>
#include "ui/ui_MainWindow.h"

#include "CommandLineDockWidget.h++"
#include "ProgramOptions.h++"



class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow (QWidget *parent = 0);

private:
	Ui::MainWindow ui;
	CommandLineDockWidget *commandLineDockWidget;
	ProgramOptions options;	// the program options

private:
	void loadOptions();

public Q_SLOTS:
	/* starts off a brand new FEM project */
	void newProject();
};


#endif
