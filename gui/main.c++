#include <sigc++/sigc++.h> 	// to side step a compiler error caused by a conflict with Qt and libsigc++

#include "FempApplication.h++"
#include "MainWindow.h++"
#include "ProgramOptions.h++"

#include <string>


Q_DECLARE_METATYPE(size_t);
Q_DECLARE_METATYPE(std::string);


int main(int argc, char *argv[])
{
	// register types
	qRegisterMetaType<size_t>("size_t");
	qRegisterMetaType<std::string>("std::string");

	FempApplication app(argc, argv);

	MainWindow main_window;
	main_window.show();

	return app.exec();
}

