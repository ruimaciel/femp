#include "FempApplication.h++"

#include "ui/MainWindow.h++"

// Qt includes
#include <QMainWindow>

FempApplication::FempApplication(int& argc, char** argv) : QApplication(argc, argv), m_main_window(nullptr) {
	// set QSettings data
	QCoreApplication::setOrganizationName("Rui Maciel");
	QCoreApplication::setOrganizationDomain("github.com/ruimaciel/");
	QCoreApplication::setApplicationName("femp");
}

void FempApplication::initialize()
{
	m_main_window = new MainWindow();
	m_main_window->show();
}