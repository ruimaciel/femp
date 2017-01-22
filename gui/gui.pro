include(../defaults.pri)

TEMPLATE = app
TARGET = femp

CONFIG += qt debug 

QT += opengl

OBJECTS_DIR += $${BUILD_DIR}/gui
DESTDIR = $${BUILD_DIR}


INCLUDEPATH += /usr/include/eigen3 /usr/include/suitesparse $${SRCDIR}}

LIBS += -lumfpack -lblas -lamd -lGLU -L$${BUILD_DIR} -llibla -llibfemp

HEADERS += MainWindow.h++ Document.h++ ProgramOptions.h++ \
	MdiWindowProperties.h++ \
	Selection*.h++ \
	ui/*.h++ \
	Project.h++ \
	ProjectVisitor/*.h++ \
	viewer/ViewportData.h++ \
	viewer/Camera.h++  \
	viewer/DisplayOptions.h++ \
	viewer/ViewportColors.h++  \
	viewer/BaseViewport.h++ \
	viewer/ModelViewport.h++ \
	viewer/PostprocessingViewport.h++ \
	viewer/TensorFieldViewport.h++ \
	viewer/ViewportStates/*.h++ \
	viewer/SceneGraph.h++ \
	viewer/RenderGroup.h++ \
	viewer/SceneGraphComponents/*.h++ \
	viewer/SceneGraphComponents/DisplacementsRepresentationPolicy/*.h++ \
	viewer/SceneGraphComponents/ElementRepresentationPolicy/*.h++ \
	viewer/SceneGraphComponents/ElementRepresentationPolicy/GradientFieldPolicy/*.h++ \
	viewer/SceneGraphComponents/ElementRepresentationPolicy/StressField/*.h++ \
	viewer/SceneGraphComponents/Elements/*.h++ \
	viewer/SceneGraphComponents/Operations/*.h++ \
	viewer/SceneGraphComponents/hud/HudObject.h++ \
	viewer/SceneGraphComponents/hud/HudSelection.h++ \
	viewer/boundaries/BoundaryStrategy.h++ \
	viewer/boundaries/SphericalBoundary.h++ \
	viewer/boundaries/CollisionDetection.h++ \
	viewer/InputStates/Input.h++ \
	viewer/InputStates/InputState.h++ \
	viewer/InputStates/ISStart.h++ \
	viewer/InputStates/ISLeftClick.h++ \
	viewer/InputStates/ISLeftDrag.h++ \
	viewer/InputStates/ISRightClick.h++ \
	viewer/InputStates/ISRightDrag.h++ \
	NodeRestrainsDialog.h++ NodeActionsDialog.h++ DisplayOptionsDialog.h++\
	DefaultProgressIndicator.h++ \

SOURCES += main.c++ \
	MainWindow.c++ \
	Document.c++ \
	ProgramOptions.c++ \
	MdiWindowProperties.c++ \
	Project.c++ \
	ProjectVisitor/*.c++ \
	Selection*.c++ \
	ui/*.c++ \
	viewer/ViewportData.c++ \
	viewer/Camera.c++ \
	viewer/DisplayOptions.c++ \
	viewer/ViewportColors.c++  \
	viewer/BaseViewport.c++ \
	viewer/ModelViewport.c++ \
	viewer/PostprocessingViewport.c++ \
	viewer/TensorFieldViewport.c++ \
	viewer/ViewportStates/*.c++  \
	viewer/SceneGraph.c++ \
	viewer/RenderGroup.c++ \
	viewer/SceneGraphComponents/*.c++ \
	viewer/SceneGraphComponents/DisplacementsRepresentationPolicy/*.c++ \
	viewer/SceneGraphComponents/ElementRepresentationPolicy/*.c++ \
	viewer/SceneGraphComponents/ElementRepresentationPolicy/GradientFieldPolicy/*.c++ \
	viewer/SceneGraphComponents/ElementRepresentationPolicy/StressField/*.c++ \
	viewer/SceneGraphComponents/Elements/*.c++ \
	viewer/SceneGraphComponents/Operations/*.c++ \
	viewer/SceneGraphComponents/hud/HudSelection.c++ \
	viewer/boundaries/BoundaryStrategy.c++ \
	viewer/boundaries/SphericalBoundary.c++  \
	viewer/boundaries/CollisionDetection.c++ \
	viewer/InputStates/Input.c++ \
	viewer/InputStates/InputState.c++ \
	viewer/InputStates/ISStart.c++ \
	viewer/InputStates/ISLeftClick.c++ \
	viewer/InputStates/ISLeftDrag.c++ \
	viewer/InputStates/ISRightClick.c++ \
	viewer/InputStates/ISRightDrag.c++ \
	NodeRestrainsDialog.c++ \
	NodeActionsDialog.c++ \
	DisplayOptionsDialog.c++ \
	DefaultProgressIndicator.c++

FORMS += ui/AnalysisDialog.ui \
	ui/AnalysisProgressDialog.ui \
	ui/AnalysisResultsWidget.ui \
	ui/AnalysisSummaryDialog.ui \
	ui/CommandLineDockWidget.ui \
	ui/DialogScale.ui \
	ui/DisplayOptionsDialog.ui \
	ui/DomainLoadsDialog.ui \
	ui/LoadPatternDialog.ui \
	ui/MainWindow.ui \
	ui/MaterialsEditorDialog.ui \
	ui/MatrixWidget.ui \
	ui/MdiWindow.ui \
	ui/MoveNodesDialog.ui \
	ui/NewMaterialDialog.ui \
	ui/NewProjectWizardPage1.ui \
	ui/NewProjectWizardPage2.ui \
	ui/NewProjectWizardPage3.ui \
	ui/NewProjectWizardPageLast.ui \
	ui/NewProjectWizard.ui \
	ui/NodeActionsDialog.ui \
	ui/NodeRestrainDialog.ui \
	ui/QuadratureRulesOptionsDialog.ui \
	ui/ResultsRangeDialog.ui \
	ui/ScalarRangeWidget.ui \
	ui/SelectionDockWidget.ui \
	ui/SelectionWidget.ui \
	ui/SurfaceSubdivisionDialog.ui \
	ui/TableFilterDialog.ui

UI_DIR += ./ui
MOC_DIR += ui/moc


ProgramOptionRe2c.target = ProgramOptions.c++
ProgramOptionRe2c.commands = re2c -o ProgramOptions.c++ ProgramOptions.c++.re2c
ProgramOptionRe2c.depends = ProgramOptions.c++.re2c
ProgramOptionRe2c.output = ProgramOptions.c++

QMAKE_EXTRA_TARGETS += ProgramOptionRe2c
