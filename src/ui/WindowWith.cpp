#include "WindowWith.hpp"

#include "../Project.hpp"

// Qt includes
#include <QMainWindow>
#include <QMenuBar>

femp::ui::WindowWith::~WindowWith() {}

void femp::ui::WindowWith::createMenuBar(::QMainWindow *, ::QMenuBar *) {}

void femp::ui::WindowWith::createToolbar(::QMainWindow *, femp::Project &) {}

void femp::ui::WindowWith::connectSignalsToSlots(::QMainWindow *) {}
