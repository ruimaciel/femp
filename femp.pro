TEMPLATE = app

CONFIG += qt debug no_keywords

QT += opengl
QMAKE_EXT_CPP += c++

LIBS += -lecl

HEADERS += MainWindow.h++ CommandLineDockWidget.h++ Document.h++ ProgramOptions.h++
SOURCES += main.c++ MainWindow.c++ CommandLineDockWidget.c++ Document.c++ ProgramOptions.c++

FORMS += ui/MainWindow.ui ui/CommandLineDockWidget.ui

UI_DIR += ./ui
OBJECTS_DIR += ./build

ProgramOptionRe2c.target = ProgramOptions.c++
ProgramOptionRe2c.commands = re2c -o ProgramOptions.c++ ProgramOptions.c++.re2c
ProgramOptionRe2c.depends = ProgramOptions.c++.re2c

QMAKE_EXTRA_TARGETS += ProgramOptionRe2c
