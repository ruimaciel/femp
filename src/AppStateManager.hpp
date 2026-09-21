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
  AppStateManager(QObject *parent);

  /**
   * @brief Sets the start state of the application
   */
  void Start();

signals:
  /**
   * @brief applicationStateChanged is emitted when the application state
   * changes
   */
  void appStateChanged(AppState state);

public slots:
  void changeApplicationState(Qt::ApplicationState state);
};

#endif