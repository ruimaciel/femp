#include <QApplication>

// #include <ecl/ecl.h>
#include "MainWindow.h++"
#include "ProgramOptions.h++"
#include "MessageLogger.h++"

#include <string>
#include <iostream>
#include <fstream>

MessageLogger mylog;


Q_DECLARE_METATYPE(size_t);
Q_DECLARE_METATYPE(std::string);

int main(int argc, char *argv[])
{
	qRegisterMetaType<size_t>("size_t");
	qRegisterMetaType<std::string>("std::string");

	QApplication app(argc, argv);

	// register types

	MainWindow mainWin;
	mainWin.show();

	return app.exec();
}

