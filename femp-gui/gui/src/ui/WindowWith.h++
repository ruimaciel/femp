#ifndef FEMP_WINDOWWITH_HPP
#define FEMP_WINDOWWITH_HPP

#include <QMainWindow>

namespace fem {
class Project;
}

/**
 * Base class that defines the interface for all WindowWith classes
 */
class WindowWith
{
public:
    virtual ~WindowWith();
    virtual void createMenuBar(QMainWindow*, QMenuBar*);
    virtual void createToolbar(QMainWindow*, fem::Project&);
    virtual void connectSignalsToSlots(QMainWindow*);
};

#endif
