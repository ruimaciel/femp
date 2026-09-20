#include "FempApplication.hpp"

#include "AppState.hpp"
#include "AppStateManager.hpp"
#include "ui/MainWindow.hpp"

// ui includes
#include <ui/MainWindow.hpp>

FempApplication::FempApplication(int &argc, char **argv)
    : QApplication(argc, argv), m_main_window(nullptr) {
  // set QSettings data
  QCoreApplication::setOrganizationName("Rui Maciel");
  QCoreApplication::setOrganizationDomain("github.com/ruimaciel/");
  QCoreApplication::setApplicationName("femp");
}

void FempApplication::initialize() {
  m_app_state_manager = new AppStateManager(this);

  m_main_window = new MainWindow();

  connect(m_app_state_manager, &AppStateManager::appStateChanged,
          m_main_window, &MainWindow::onAppStateChanged);

  m_app_state_manager->setStartState();
}