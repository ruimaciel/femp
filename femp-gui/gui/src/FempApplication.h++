#ifndef FEMP_FEMPAPPLICATION_H
#define FEMP_FEMPAPPLICATION_H

#include <QApplication>

class FempApplication : public QApplication {
   public:
	FempApplication(int& argc, char** argv);
};

#define fempApp dynamic_cast<FempApplication*>(QApplication::instance())

#endif	// FEMPAPPLICATION_H
