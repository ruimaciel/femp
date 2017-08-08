INCLUDEPATH += $$PWD

BUILD_DIR += $${PWD}/build

QMAKE_CXXFLAGS += -std=c++11
QMAKE_CXXFLAGS_DEBUG +=-O0 -Wfatal-errors -ggdb

QMAKE_EXT_CPP += c++

CONFIG += debug

