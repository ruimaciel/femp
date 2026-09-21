#ifndef FEMP_APPSTATE_H
#define FEMP_APPSTATE_H

enum class ApplicationLifeCycleState {
  AppStateUnknown = 0,
  AppStateStart,
  AppStateActive,
  AppStateInactive
};

enum class DocumentState {
  DocumentStateUnknown = 0,
  DocumentStateOpen,
  DocumentStateClosed
};

/**
 * @brief The AppState struct represents the state of the application. It
 * is a composite state that contains information.
 */
struct AppState {
  ApplicationLifeCycleState lifeCycleState;
  DocumentState documentState;

  static AppState createStartState() {
    return AppState{ApplicationLifeCycleState::AppStateStart,
                    DocumentState::DocumentStateClosed};
  }
};

#endif