TEMPLATE = app

CONFIG += qt debug no_keywords

QT += opengl
QMAKE_EXT_CPP += c++

LIBS += -lecl

SOURCES += main.c++ MainWindow.c++ CommandLineDockWidget.c++ Document.c++ 
HEADERS += MainWindow.h++ CommandLineDockWidget.h++ Document.h++ 

FORMS += ui/MainWindow.ui ui/CommandLineDockWidget.ui

UI_DIR += ./ui
