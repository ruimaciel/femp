#ifndef FEMP_FEMPAPPLICATION_HPP
#define FEMP_FEMPAPPLICATION_HPP

// Qt includes
#include <QApplication>

class QMainWindow;

class FempApplication : public QApplication {
	public:
	FempApplication(int& argc, char** argv);

	/**
	 * initializes the applicaiton before running the event loop
	 */
	void initialize();

	private:
	QMainWindow* m_main_window;
};

#define fempApp dynamic_cast<FempApplication*>(QApplication::instance())

#endif	// FEMPAPPLICATION_HPP
