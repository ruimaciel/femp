#ifndef FEMPAPPLICATION_H
#define FEMPAPPLICATION_H

#include <QApplication>

class FempApplication : public QApplication
{
public:
	FempApplication(int &argc, char ** argv);
};

#endif // FEMPAPPLICATION_H
