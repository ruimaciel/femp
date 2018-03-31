include(../defaults.pri)

TEMPLATE = lib

CONFIG += staticlib link_pkgconfig

PKGCONFIG += eigen3

CONFIG -= qt

OBJECTS_DIR += $${BUILD_DIR}/libla

DESTDIR = $${BUILD_DIR}

INCLUDEPATH += /usr/include/suitesparse

LIBS += -lumfpack -lblas -lamd -lGLU


HEADERS = Matrix.h++ \
	Vector.h++ \
	ProgressIndicatorStrategy.h++ \
	solvers/*.h++ 

SOURCES = solvers/Umfpack.c++

