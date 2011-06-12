TEMPLATE = app

CONFIG += qt debug 
QMAKE_CXXFLAGS += -std=c++0x
QMAKE_CXXFLAGS_DEBUG +=-O0 -Wfatal-errors -std=c++0x

QT += opengl
QMAKE_EXT_CPP += c++

INCLUDEPATH += /usr/include/eigen2 /usr/include/suitesparse
LIBS += -ll -ly -lumfpack -lmetis -lblas -lamd

HEADERS += MainWindow.h++ CommandLineDockWidget.h++ Document.h++ ProgramOptions.h++ NewProjectWizard.h++ \
	ModelSelection.h++ \
	MdiWindowProperties.h++ \
	ui/NewProjectWizardPage1.h++ ui/NewProjectWizardPage2.h++ ui/NewProjectWizardPage3.h++ ui/NewProjectWizardPageLast.h++ \
	ui/QuadratureRulesOptionsDialog.h++ \
	fem/Project.h++ \
	fem/Model.h++ fem/Node.h++ fem/Element.h++ fem/Material.h++ fem/LoadPattern.h++ fem/NodalLoad.h++ fem/NodalDisplacement.h++ fem/point.h++ fem/NodeRestrictions.h++ \
	fem/DomainLoad.h++ fem/SurfaceLoad.h++\
	fem/elements/Triangle3.h++ fem/elements/Triangle6.h++ \
	fem/elements/Quadrangle4.h++ fem/elements/Quadrangle8.h++ fem/elements/Quadrangle9.h++ \
	fem/elements/Hexahedron8.h++ fem/elements/Hexahedron20.h++ fem/elements/Hexahedron27.h++ \
	fem/elements/Tetrahedron4.h++ fem/elements/Tetrahedron10.h++ \
	fem/elements/Prism6.h++ \
	fem/elements/Prism18.h++ \
	viewer/ViewportData.h++ \
	viewer/Camera.h++  viewer/DisplayOptions.h++  viewer/ViewportColors.h++  \
	viewer/BaseViewport.h++ viewer/ModelViewport.h++ viewer/DisplacementsViewport.h++  viewer/PostprocessingViewport.h++ \
	viewer/ViewportStates/ViewportState.h++  viewer/ViewportStates/VPStateModel.h++ viewer/ViewportStates/VPStateDisplacements.h++ viewer/ViewportStates/VPStateModel.h++ \
	viewer/SceneGraph.h++ viewer/SceneGraphComponents/SceneGraphComponent.h++  \
	viewer/SceneGraphComponents/SGCNode.h++ \
	viewer/SceneGraphComponents/SGCNodeRestrictions.h++ \
	viewer/SceneGraphComponents/SGCDisplacementSurface.h++ viewer/SceneGraphComponents/SGCDisplacementOriginalSurface.h++ \
	viewer/SceneGraphComponents/SGCModelSurface.h++ \
	viewer/SceneGraphComponents/OpaqueSurface/*.h++ \
	viewer/SceneGraphComponents/WireframeSurface/*.h++ \
	viewer/boundaries/BoundaryStrategy.h++ viewer/boundaries/SphericalBoundary.h++ \
	fem_msh.h++ lex.msh_yy.h \
	parsers/parser.h++ parsers/msh.h++ parsers/json.h \
	NodeRestrainsDialog.h++ NodeActionsDialog.h++ DisplayOptionsDialog.h++\
	ui/NewMaterialDialog.h++ ui/MaterialsEditorDialog.h++\
	fem/Analysis.h++ fem/LinearAnalysis.h++ fem/AnalysisResult.h++\
	fem/ProgressIndicatorStrategy.h++ \
	fem/solvers/Solver.h++ fem/solvers/CholeskySolver.h++ fem/solvers/CGSolver.h++ fem/solvers/UmfpackSolver.h++\
	DefaultProgressIndicator.h++ \
	ui/DialogScale.h++ \
	MessageLogger.h++ Logs.h++ \
	fem/Surface.h++ \
	viewer/boundaries/CollisionDetection.h++ \
	lalib/Matrix.h++ lalib/Vector.h++ lalib/solvers/*.h++ \
	ui/AnalysisDialog.h++ \
	fem/solvers/*.h++ \
	ui/AnalysisProgressDialog.h++ \
	ui/MdiWindow.h++ ui/ModelWindow.h++ ui/DisplacementsWindow.h++ ui/PostprocessingWindow.h++ \
	ui/WindowWithResults.h++ ui/WindowWithPostprocessing.h++

SOURCES += main.c++ MainWindow.c++ CommandLineDockWidget.c++ Document.c++ ProgramOptions.c++ NewProjectWizard.c++ \
	ModelSelection.c++ \
	MdiWindowProperties.c++ \
	ui/NewProjectWizardPage1.c++ ui/NewProjectWizardPage2.c++ ui/NewProjectWizardPage3.c++ ui/NewProjectWizardPageLast.c++  \
	ui/QuadratureRulesOptionsDialog.c++ \
	fem/Project.c++ \
	fem/Model.c++ fem/Node.c++ fem/Element.c++ fem/Material.c++ fem/LoadPattern.c++ fem/NodalLoad.c++ fem/NodalDisplacement.c++ fem/point.c++ fem/NodeRestrictions.c++ \
	fem/DomainLoad.c++ fem/SurfaceLoad.c++\
	viewer/ViewportData.c++ \
	viewer/Camera.c++  viewer/DisplayOptions.c++  viewer/ViewportColors.c++  \
	viewer/BaseViewport.c++ viewer/ModelViewport.c++ viewer/DisplacementsViewport.c++  viewer/PostprocessingViewport.c++ \
	viewer/ViewportStates/VPStateModel.c++ viewer/ViewportStates/VPStateDisplacements.c++ viewer/ViewportStates/VPStateStrain11.c++  \
	viewer/SceneGraph.c++ viewer/SceneGraphComponents/SceneGraphComponent.c++ \
	viewer/SceneGraphComponents/SGCNode.c++ \
	viewer/SceneGraphComponents/SGCNodeRestrictions.c++ \
	viewer/SceneGraphComponents/OpaqueSurface/SurfaceTriangle3.c++\
	viewer/SceneGraphComponents/OpaqueSurface/SurfaceTriangle6.c++\
	viewer/SceneGraphComponents/OpaqueSurface/SurfaceQuad4.c++\
	viewer/SceneGraphComponents/OpaqueSurface/SurfaceQuad8.c++\
	viewer/SceneGraphComponents/OpaqueSurface/SurfaceQuad9.c++\
	viewer/boundaries/BoundaryStrategy.c++  viewer/boundaries/SphericalBoundary.c++  \
	fem_msh.c++ lex.msh_yy.c++ \
	parsers/parser.c++ parsers/msh.c++ parsers/json.c \
	NodeRestrainsDialog.c++ NodeActionsDialog.c++ DisplayOptionsDialog.c++ \
	ui/NewMaterialDialog.c++ ui/MaterialsEditorDialog.c++\
	DefaultProgressIndicator.c++ \
	ui/DialogScale.c++ \
	MessageLogger.c++ \
	fem/Surface.c++ \
	viewer/boundaries/CollisionDetection.c++ \
	ui/AnalysisDialog.c++ \
	ui/AnalysisProgressDialog.c++ \
	ui/MdiWindow.c++ ui/ModelWindow.c++ ui/DisplacementsWindow.c++ ui/PostprocessingWindow.c++ \
	ui/WindowWithResults.c++ ui/WindowWithPostprocessing.c++

FORMS += ui/MainWindow.ui ui/CommandLineDockWidget.ui \
	ui/NewProjectWizardPage1.ui ui/NewProjectWizardPage2.ui ui/NewProjectWizardPage3.ui  ui/NewProjectWizardPageLast.ui \
	ui/NodeRestrainDialog.ui ui/NodeActionsDialog.ui ui/DisplayOptionsDialog.ui \
	ui/NewMaterialDialog.ui ui/MaterialsEditorDialog.ui \
	ui/DialogScale.ui \
	ui/QuadratureRulesOptionsDialog.ui \
	ui/AnalysisDialog.ui \
	ui/AnalysisProgressDialog.ui \
	ui/MdiWindow.ui

UI_DIR += ./ui
OBJECTS_DIR += ./build

MshParserRe2c.target = fem/msh.c++
MshParserRe2c.commands = re2c -o fem/msh.c++ fem/msh.c++.re2c
MshParserRe2c.depends = fem/msh.c++.re2c
MshParserRe2c.output = fem/msh.c++

ProgramOptionRe2c.target = ProgramOptions.c++
ProgramOptionRe2c.commands = re2c -o ProgramOptions.c++ ProgramOptions.c++.re2c
ProgramOptionRe2c.depends = ProgramOptions.c++.re2c
ProgramOptionRe2c.output = ProgramOptions.c++

ElementRe2c.target = fem/Element.c++
ElementRe2c.commands = re2c -o fem/Element.c++ fem/Element.c++.re2c
ElementRe2c.depends = fem/Element.c++.re2c
ElementRe2c.output = fem/Element.c++

FlexOutput.target = lex.msh_yy.h 
FlexOutput.commands = flex --header-file=lex.msh_yy.h -o lex.msh_yy.c++ msh.l
FlexOutput.depends = msh.l
FlexOutput.output = lex.msh_yy.c++ lex.msh_yy.h

BisonOutput.target = msh.tab.h
BisonOutput.commands = bison -d --debug msh.y
BisonOutput.depends = msh.y lex.msh_yy.h
BisonOutput.output = msh.tab.c msh.tab.h

BisonCompile.target = msh.tab.o
BisonCompile.commands = g++ -c msh.tab.c $(INCPATH)
BisonCompile.depends = msh.tab.h
BisonCompile.output = msh.tab.o

OBJECTS += msh.tab.o
QMAKE_CLEAN += lex.msh_yy.h lex.msh_yy.c++ msh.tab.c msh.tab.h msh.tab.o

QMAKE_EXTRA_TARGETS += MshParserRe2c ProgramOptionRe2c  ElementRe2c FlexOutput BisonOutput BisonCompile 
