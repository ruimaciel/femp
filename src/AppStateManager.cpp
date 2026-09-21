#include "AppStateManager.hpp"

#include <QDebug>

AppStateManager::AppStateManager(QObject *parent)
        : QObject(parent),
            m_state{ApplicationLifeCycleState::AppStateUnknown,
                            DocumentState::DocumentStateUnknown} {}

AppState AppStateManager::state() const { return m_state; }

void AppStateManager::start()
{
    updateState(AppState::createStartState());
}

void AppStateManager::changeDocumentState(DocumentState state)
{
    AppState nextState = m_state;
    nextState.documentState = state;
    updateState(nextState);
}

void AppStateManager::changeApplicationState(Qt::ApplicationState state)
{
    AppState nextState = m_state;
    nextState.lifeCycleState =
            state == Qt::ApplicationActive
                    ? ApplicationLifeCycleState::AppStateActive
                    : ApplicationLifeCycleState::AppStateInactive;
    updateState(nextState);
}

void AppStateManager::updateState(AppState state)
{
    if (m_state == state) {
        return;
    }

    m_state = state;
    emit appStateChanged(m_state);
}
