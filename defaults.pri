INCLUDEPATH += $$PWD

BUILD_DIR += $${PWD}/build

QMAKE_CXXFLAGS += -std=c++11
QMAKE_CXXFLAGS_DEBUG +=-O0 -Wfatal-errors

QMAKE_EXT_CPP += c++

CONFIG += debug

LIBFEMP_SRC = $${PWD}/libfemp
