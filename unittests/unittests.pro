include(../defaults.pri)

TEMPLATE = app

CONFIG += qtestlib

OBJECTS_DIR += $${BUILD_DIR}/unit_tests
MOC_DIR += $${BUILD_DIR}/unit_tests/moc
DESTDIR = $${BUILD_DIR}

QT += testlib

SOURCES = main.c++ \
	  TestLa.c++ \
	  TestFemp.c++

HEADERS = TestLa.h++ \
	  TestFemp.h++

LIBS += -lumfpack -lblas -lamd -lGLU -L$${BUILD_DIR} -llibla -llibfemp
