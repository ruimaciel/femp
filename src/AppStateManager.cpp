#include "AppStateManager.hpp"

#include <QDebug>

AppStateManager::AppStateManager(QObject *parent) {}

void AppStateManager::Start()
{
    emit appStateChanged(AppState::createStartState());
}

void AppStateManager::changeApplicationState(Qt::ApplicationState state)
{
    qDebug() << "Application state changed to:" << state;
}
