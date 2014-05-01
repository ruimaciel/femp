TEMPLATE = app

CONFIG += link_pkgconfig qt debug 
QMAKE_CXXFLAGS += -std=c++0x
QMAKE_CXXFLAGS_DEBUG +=-O0 -Wfatal-errors -std=c++0x

PKGCONFIG += sigc++-2.0

QT += opengl
QMAKE_EXT_CPP += c++

INCLUDEPATH += /usr/include/eigen2 /usr/include/suitesparse
LIBS += -lumfpack -lblas -lamd -lGLU

HEADERS += MainWindow.h++ Document.h++ ProgramOptions.h++ \
	ModelSelection.h++ \
	MdiWindowProperties.h++ \
	Selection*.h++ \
	ui/*.h++ \
	fem/Project.h++ \
	fem/Group.h++ \
	fem/Model.h++ fem/Node.h++ fem/Element.h++ fem/Material.h++ fem/LoadPattern.h++ fem/NodalLoad.h++ fem/NodalDisplacement.h++ fem/point.h++ fem/NodeRestrictions.h++ \
	fem/DomainLoad.h++ fem/SurfaceLoad.h++ \
	fem/ElementGroup.h++ fem/NodeGroup.h++ \
	fem/ProjectVisitor/*.h++ \
	fem/elements/Triangle3.h++ fem/elements/Triangle6.h++ \
	fem/elements/Quadrangle4.h++ fem/elements/Quadrangle8.h++ fem/elements/Quadrangle9.h++ \
	fem/elements/Hexahedron8.h++ fem/elements/Hexahedron20.h++ fem/elements/Hexahedron27.h++ \
	fem/elements/Tetrahedron4.h++ fem/elements/Tetrahedron10.h++ \
	fem/elements/Prism6.h++ \
	fem/elements/Prism18.h++ \
	fem/SurfaceLoadOperators/*.h++ \
	viewer/ViewportData.h++ \
	viewer/Camera.h++  viewer/DisplayOptions.h++  viewer/ViewportColors.h++  \
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
	viewer/boundaries/BoundaryStrategy.h++ viewer/boundaries/SphericalBoundary.h++ \
	viewer/boundaries/CollisionDetection.h++ \
	viewer/InputStates/Input.h++ \
	viewer/InputStates/InputState.h++ \
	viewer/InputStates/ISStart.h++ \
	viewer/InputStates/ISLeftClick.h++ \
	viewer/InputStates/ISLeftDrag.h++ \
	viewer/InputStates/ISRightClick.h++ \
	viewer/InputStates/ISRightDrag.h++ \
	fem_msh.h++ lex.msh_yy.h \
	parsers/parser.h++ parsers/MshParser.h++ parsers/json.h parsers/FemJsonParser.h++\
	NodeRestrainsDialog.h++ NodeActionsDialog.h++ DisplayOptionsDialog.h++\
	fem/Analysis.h++ fem/LinearAnalysis.h++ fem/AnalysisResult.h++\
	fem/ProgressIndicatorStrategy.h++ \
	fem/solvers/Solver.h++ fem/solvers/CholeskySolver.h++ fem/solvers/CGSolver.h++ fem/solvers/UmfpackSolver.h++\
	DefaultProgressIndicator.h++ \
	fem/Surface.h++ \
	lalib/Matrix.h++ lalib/Vector.h++ lalib/solvers/*.h++ \
	fem/solvers/*.h++

SOURCES += main.c++ MainWindow.c++ Document.c++ ProgramOptions.c++ \
	ModelSelection.c++ \
	MdiWindowProperties.c++ \
	Selection*.c++ \
	ui/*.c++ \
	fem/Project.c++ \
	fem/Group.c++ \
	fem/Model.c++ fem/Node.c++ fem/Element.c++ fem/Material.c++ fem/LoadPattern.c++ fem/NodalLoad.c++ fem/NodalDisplacement.c++ fem/point.c++ fem/NodeRestrictions.c++ \
	fem/DomainLoad.c++ fem/SurfaceLoad.c++\
	fem/ElementGroup.c++ fem/NodeGroup.c++ \
	fem/ProjectVisitor/*.c++ \
	fem/SurfaceLoadOperators/*.c++ \
	viewer/ViewportData.c++ \
	viewer/Camera.c++  viewer/DisplayOptions.c++  viewer/ViewportColors.c++  \
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
	viewer/boundaries/BoundaryStrategy.c++  viewer/boundaries/SphericalBoundary.c++  \
	viewer/boundaries/CollisionDetection.c++ \
	viewer/InputStates/Input.c++ \
	viewer/InputStates/InputState.c++ \
	viewer/InputStates/ISStart.c++ \
	viewer/InputStates/ISLeftClick.c++ \
	viewer/InputStates/ISLeftDrag.c++ \
	viewer/InputStates/ISRightClick.c++ \
	viewer/InputStates/ISRightDrag.c++ \
	fem_msh.c++ lex.msh_yy.c++ \
	parsers/parser.c++ parsers/MshParser.c++ parsers/json.c parsers/FemJsonParser.c++\
	NodeRestrainsDialog.c++ NodeActionsDialog.c++ DisplayOptionsDialog.c++ \
	DefaultProgressIndicator.c++ \
	fem/Surface.c++ 

FORMS += ui/*.ui

UI_DIR += ./ui
OBJECTS_DIR += ./build

FemJsonParserRe2c.target = parsers/FemJsonParser.c++
FemJsonParserRe2c.commands = re2c -o parsers/FemJsonParser.c++ parsers/FemJsonParser.c++.re2c
FemJsonParserRe2c.depends = parsers/FemJsonParser.c++.re2c fem/Model.h++ fem/Model.c++
FemJsonParserRe2c.output = parsers/FemJsonParser.c++

MshParserRe2c.target = parsers/MshParser.c++
MshParserRe2c.commands = re2c -o parsers/MshParser.c++ parsers/MshParser.c++.re2c
MshParserRe2c.depends = parsers/MshParser.c++.re2c
MshParserRe2c.output = parsers/MshParser.c++

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
FlexOutput.depends = msh.l fem/Model.h++ fem/Model.c++
FlexOutput.output = lex.msh_yy.c++ lex.msh_yy.h

BisonOutput.target = msh.tab.h
BisonOutput.commands = bison -d --debug msh.y
BisonOutput.depends = msh.y lex.msh_yy.h fem/Model.h++ fem/Model.c++
BisonOutput.output = msh.tab.c msh.tab.h

BisonCompile.target = msh.tab.o
BisonCompile.commands = g++ -c msh.tab.c $(INCPATH)
BisonCompile.depends = msh.tab.h
BisonCompile.output = msh.tab.o

OBJECTS += msh.tab.o
QMAKE_CLEAN += lex.msh_yy.h lex.msh_yy.c++ msh.tab.c msh.tab.h msh.tab.o

QMAKE_EXTRA_TARGETS += FemJsonParserRe2c MshParserRe2c ProgramOptionRe2c  ElementRe2c FlexOutput BisonOutput BisonCompile 
