#include <QApplication>

// #include <ecl/ecl.h>
#include "MainWindow.h++"
#include "ProgramOptions.h++"

#include <string>
#include <iostream>
#include <fstream>

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);

	// cl_boot(argc, argv);

	MainWindow mainWin;
	mainWin.show();

	// cl_shutdown();
	return app.exec();
}

