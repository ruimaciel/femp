#include "WindowWith.hpp"

#include "../Project.hpp"

// Qt includes
#include <QMainWindow>
#include <QMenuBar>

WindowWith::~WindowWith() {}

void WindowWith::createMenuBar(QMainWindow*, QMenuBar*) {}

void WindowWith::createToolbar(QMainWindow*, fem::Project&) {}

void WindowWith::connectSignalsToSlots(QMainWindow*) {}