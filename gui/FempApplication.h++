#ifndef FEMPAPPLICATION_H
#define FEMPAPPLICATION_H

#include <QApplication>

#include "Settings.h++"

class FempApplication : public QApplication
{
public:
	FempApplication(int &argc, char ** argv);

	Settings & settings();

private:
	Settings m_settings;
};

#define fempApp dynamic_cast<FempApplication *>(QApplication::instance())

#endif // FEMPAPPLICATION_H
