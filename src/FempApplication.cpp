#include "FempApplication.hpp"

#include "AppStateManager.hpp"

// ui includes
#include <ui/MainWindow.hpp>

FempApplication::FempApplication(int &argc, char **argv)
    : QApplication(argc, argv), m_app_state_manager(nullptr),
      m_main_window(nullptr) {
  // set QSettings data
  QCoreApplication::setOrganizationName("Rui Maciel");
  QCoreApplication::setOrganizationDomain("github.com/ruimaciel/");
  QCoreApplication::setApplicationName("femp");
}

void FempApplication::initialize() {
  m_app_state_manager = new femp::AppStateManager(this);

  m_main_window = new MainWindow();

  connect(this, &QApplication::applicationStateChanged,
          m_app_state_manager, &femp::AppStateManager::changeApplicationState);

  connect(m_main_window, &MainWindow::documentOpened, m_app_state_manager,
          [this]() {
            m_app_state_manager->changeDocumentState(
                femp::DocumentState::DocumentStateOpen);
          });
  connect(m_main_window, &MainWindow::documentClosed, m_app_state_manager,
          [this]() {
            m_app_state_manager->changeDocumentState(
                femp::DocumentState::DocumentStateClosed);
          });

  connect(m_app_state_manager, &femp::AppStateManager::appStateChanged,
          m_main_window, &MainWindow::onAppStateChanged);

  m_app_state_manager->start();
}