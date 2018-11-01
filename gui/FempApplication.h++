#ifndef FEMPAPPLICATION_H
#define FEMPAPPLICATION_H

#include <QApplication>

#include "FempSettings.h++"

class FempApplication : public QApplication
{
public:
	FempApplication(int &argc, char ** argv);

};

#define fempApp dynamic_cast<FempApplication *>(QApplication::instance())

#endif // FEMPAPPLICATION_H
