include(../defaults.pri)

TEMPLATE = app

CONFIG += qtestlib

QT += testlib

SOURCES = main.c++ \
	  TestLa.c++ \
	  TestFemp.c++

HEADERS = TestLa.h++ \
	  TestFemp.h++

LIBS += -lumfpack -lblas -lamd -lGLU -L$${BUILD_DIR} -llibla -llibfemp
