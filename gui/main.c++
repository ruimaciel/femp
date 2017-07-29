#include <sigc++/sigc++.h> 	// to side step a compiler error caused by a conflict with Qt and libsigc++
#include <QApplication>

#include "MainWindow.h++"
#include "ProgramOptions.h++"

#include <string>


Q_DECLARE_METATYPE(size_t);
Q_DECLARE_METATYPE(std::string);


int main(int argc, char *argv[])
{
	qRegisterMetaType<size_t>("size_t");
	qRegisterMetaType<std::string>("std::string");

	// set QSettings data
	QCoreApplication::setOrganizationName("Rui Maciel");
	QCoreApplication::setOrganizationDomain("github.com/ruimaciel/");
	QCoreApplication::setApplicationName("femp");

	QApplication app(argc, argv);

	// register types

	MainWindow main_window;
	main_window.show();

	return app.exec();
}

