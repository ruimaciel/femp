TEMPLATE = app

CONFIG += qt debug
QT += opengl
QMAKE_EXT_CPP += c++

SOURCES += main.c++ MainWindow.c++ CommandLineDockWidget.c++
HEADERS += MainWindow.h++ CommandLineDockWidget.h++

FORMS += ui/MainWindow.ui ui/CommandLineDockWidget.ui

UI_DIR += ./ui
