#ifndef FEMP_FEMPAPPLICATION_HPP
#define FEMP_FEMPAPPLICATION_HPP

// Qt includes
#include <QApplication>

namespace femp {
class AppStateManager;
}

class MainWindow;

class FempApplication : public QApplication {
  Q_OBJECT

public:
  FempApplication(int &argc, char **argv);

  /**
   * initializes the application before running the event loop
   */
  void initialize();

private:
  femp::AppStateManager *m_app_state_manager;
  MainWindow *m_main_window;
};

#define fempApp dynamic_cast<FempApplication *>(QApplication::instance())

#endif // FEMPAPPLICATION_HPP
