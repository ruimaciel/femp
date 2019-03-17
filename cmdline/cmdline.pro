include(../defaults.pri)

TEMPLATE = app
TARGET = clfemp

CONFIG -= qt

OBJECTS_DIR += $${BUILD_DIR}/cmdline
DESTDIR = $${BUILD_DIR}


INCLUDEPATH += \
    /usr/include/eigen3 \
    /usr/include/suitesparse \
    ../libla/include \
    ../libfemp/include

LIBS += -L$${BUILD_DIR} -llibla -llibfemp

HEADERS += ProgramOptions.h

SOURCES += main.c++ \
    ProgramOptions.c++


ProgramOptionRe2c.target = ProgramOptions.c++
ProgramOptionRe2c.commands = re2c -o ProgramOptions.c++ ProgramOptions.c++.re2c
ProgramOptionRe2c.depends = ProgramOptions.c++.re2c
ProgramOptionRe2c.output = ProgramOptions.c++



QMAKE_EXTRA_TARGETS += ProgramOptionRe2c
