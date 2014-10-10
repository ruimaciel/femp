TEMPLATE = subdirs

CONFIG+=ordered

SUBDIRS = \
	libla \
	libfemp \
	gui \
	unittests

libfemp.depends = libla
gui.depends = libla libfemp
tests.depends = gui
