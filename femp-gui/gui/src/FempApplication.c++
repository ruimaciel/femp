#include "FempApplication.h++"

FempApplication::FempApplication(int& argc, char** argv) : QApplication(argc, argv) {
	// set QSettings data
	QCoreApplication::setOrganizationName("Rui Maciel");
	QCoreApplication::setOrganizationDomain("github.com/ruimaciel/");
	QCoreApplication::setApplicationName("femp");
}
