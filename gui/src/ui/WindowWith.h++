#ifndef FEMP_WINDOWWITH_HPP
#define FEMP_WINDOWWITH_HPP

#include <sigc++/sigc++.h> // to side step a compiler error caused by a conflict with Qt and libsigc++

#include <QMainWindow>

namespace fem {
class Project;
}

/**
Base class that defines the interface for all WindowWith classes
**/
class WindowWith {
public:
    virtual ~WindowWith();
    virtual void createMenuBar(QMainWindow*, QMenuBar*);
    virtual void createToolbar(QMainWindow*, fem::Project&);
    virtual void connectSignalsToSlots(QMainWindow*);
};

#endif
