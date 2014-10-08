# http://comp-phys.net/2014/03/13/new-project-structure-for-projects-in-qt-creator-with-unit-tests/

TEMPLATE = subdirs

CONFIG+=ordered

SUBDIRS = \
    gui \
    unittests

tests.depends = gui
