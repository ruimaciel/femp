#ifndef FEMP_APPSTATEMANAGER_HPP
#define FEMP_APPSTATEMANAGER_HPP

#include "AppState.hpp"

// Qt includes
#include <QObject>

/**
 * @brief The AppStateManager class is responsible for managing the state of the
 * application. It handles the saving and loading of application settings, user
 * preferences, and other state-related data
 */
class AppStateManager : public QObject {
  Q_OBJECT

public:
  explicit AppStateManager(QObject *parent = nullptr);

  AppState state() const;

  /**
   * @brief Sets the start state of the application
   */
  void start();

signals:
  /**
   * @brief applicationStateChanged is emitted when the application state
   * changes
   */
  void appStateChanged(AppState state);

public slots:
  void changeDocumentState(DocumentState state);
  void changeApplicationState(Qt::ApplicationState state);

private:
  void updateState(AppState state);

  AppState m_state;
};

#endif