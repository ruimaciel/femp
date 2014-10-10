include(../defaults.pri)

TEMPLATE = lib

CONFIG += staticlib

OBJECTS_DIR += $${BUILD_DIR}/libla
DESTDIR = $${BUILD_DIR}

INCLUDEPATH += /usr/include/eigen2 /usr/include/suitesparse

LIBS += -lumfpack -lblas -lamd -lGLU


HEADERS = Matrix.h++ \
	Vector.h++ \
	ProgressIndicatorStrategy.h++ \
	solvers/*.h++ 

SOURCES =

