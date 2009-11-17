TEMPLATE = app

CONFIG += qt debug no_keywords

QT += opengl
QMAKE_EXT_CPP += c++

# LIBS += -lecl

HEADERS += MainWindow.h++ CommandLineDockWidget.h++ Document.h++ ProgramOptions.h++ NewProjectWizard.h++ \
	ui/NewProjectWizardPage1.h++ ui/NewProjectWizardPage2.h++ ui/NewProjectWizardPageLast.h++ \
	fem/Model.h++ fem/Node.h++ fem/Element.h++ fem/Material.h++ fem/LoadPattern.h++ fem/NodalLoad.h++ fem/point.h++ \
	Camera.h++ glwidget.h++

SOURCES += main.c++ MainWindow.c++ CommandLineDockWidget.c++ Document.c++ ProgramOptions.c++ NewProjectWizard.c++ \
	ui/NewProjectWizardPage1.c++ ui/NewProjectWizardPage2.c++ ui/NewProjectWizardPageLast.c++  \
	fem/Model.c++ fem/Node.c++ fem/Element.c++ fem/Material.c++ fem/LoadPattern.c++ fem/NodalLoad.c++ fem/point.c++ \
	Camera.c++ glwidget.c++

FORMS += ui/MainWindow.ui ui/CommandLineDockWidget.ui ui/NewProjectWizardPage1.ui ui/NewProjectWizardPage2.ui ui/NewProjectWizardPageLast.ui 

UI_DIR += ./ui
OBJECTS_DIR += ./build

ProgramOptionRe2c.target = ProgramOptions.c++
ProgramOptionRe2c.commands = re2c -o ProgramOptions.c++ ProgramOptions.c++.re2c
ProgramOptionRe2c.depends = ProgramOptions.c++.re2c

QMAKE_EXTRA_TARGETS += ProgramOptionRe2c
