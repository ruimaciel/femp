INCLUDEPATH += $$PWD

BUILD_DIR += $${PWD}/build

QMAKE_CXXFLAGS += -std=c++0x
QMAKE_CXXFLAGS_DEBUG +=-O0 -Wfatal-errors -std=c++0x

QMAKE_EXT_CPP += c++

CONFIG += link_pkgconfig 

PKGCONFIG += sigc++-2.0

LIBFEMP_SRC = $${PWD}/libfemp
