TEMPLATE = subdirs

CONFIG+=ordered debug c++11

SUBDIRS = \
	libla \
	libfemp \
	cmdline \
	gui \
	unittests

libfemp.depends = libla
gui.depends = libfemp
cmdline.depends = libfemp
tests.depends = libla libfemp
