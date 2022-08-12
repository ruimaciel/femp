#include <QScopedPointer>
#include <string>

#include "FempApplication.h++"
#include "ui/MainWindow.h++"

Q_DECLARE_METATYPE(size_t);
Q_DECLARE_METATYPE(std::string);

int main(int argc, char* argv[]) {
	// register types
	qRegisterMetaType<size_t>("size_t");
	qRegisterMetaType<std::string>("std::string");

	FempApplication app(argc, argv);

	QScopedPointer<MainWindow> main_window(new MainWindow);
	main_window->show();

	return app.exec();
}
