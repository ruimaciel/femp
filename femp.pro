TEMPLATE = subdirs

CONFIG+=ordered debug c++11

SUBDIRS = \
	libla \
	libfemp \
	cmdline \
	gui 

libfemp.depends = libla
gui.depends = libfemp
cmdline.depends = libfemp
