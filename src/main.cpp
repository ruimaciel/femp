#include <string>

#include "FempApplication.hpp"

Q_DECLARE_METATYPE(size_t);
Q_DECLARE_METATYPE(std::string);

int main(int argc, char* argv[]) {
	// register types
	qRegisterMetaType<size_t>("size_t");
	qRegisterMetaType<std::string>("std::string");

	FempApplication app(argc, argv);
	app.initialize();

	return app.exec();
}