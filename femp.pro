TEMPLATE = subdirs

CONFIG+=ordered debug

SUBDIRS = \
	libla \
	libfemp \
	cmdline \
	gui \
	unittests

libfemp.depends = libla
gui.depends = libla libfemp
cmdline.depends = libla libfemp
tests.depends = gui cmdline
