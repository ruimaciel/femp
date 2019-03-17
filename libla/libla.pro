include(../defaults.pri)

TEMPLATE = lib

CONFIG += staticlib link_pkgconfig

PKGCONFIG += eigen3

CONFIG -= qt

OBJECTS_DIR += $${BUILD_DIR}/libla

DESTDIR = $${BUILD_DIR}

INCLUDEPATH += /usr/include/suitesparse ./include

LIBS += -lumfpack -lblas -lamd -lGLU

HEADERS = \
    include/la/Matrix.h++ \
    include/la/Vector.h++ \
    include/la/ProgressIndicatorStrategy.h++ \
    include/la/solvers/CG.h++ \
    include/la/solvers/Cholesky.h++ \
    include/la/solvers/SolverReturnCodes.h++ \
    include/la/solvers/substitution.h++ \
    include/la/solvers/Umfpack.h++

SOURCES = src/solvers/Umfpack.c++

