#include "AppStateManager.hpp"

#include <QDebug>

AppStateManager::AppStateManager(QObject *parent) {}

void AppStateManager::setStartState()
{
    emit appStateChanged(AppStateStart);
}

void AppStateManager::changeApplicationState(Qt::ApplicationState state)
{
    qDebug() << "Application state changed to:" << state;
}
