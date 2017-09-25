include(../defaults.pri)

TEMPLATE = lib

CONFIG += staticlib
CONFIG -= qt

OBJECTS_DIR += $${BUILD_DIR}/libfemp
DESTDIR = $${BUILD_DIR}

INCLUDEPATH += /usr/include/eigen3

LIBS += -lumfpack -lblas -lamd -lGLU -llibla


HEADERS = Group.h++ \
	Model.h++ \
	Node.h++ \
	GlobalDof.h++ \
	GlobalDofMap.h++ \
	Element.h++ \
	Material.h++ \
	LoadPattern.h++ \
	NodalLoad.h++ \
	NodalDisplacement.h++ \
	Point.h++ \
	Point2D.h++ \
	NodeRestrictions.h++ \
	DomainLoad.h++ \
	SurfaceLoad.h++ \
	ElementGroup.h++ \
	NodeGroup.h++ \
	elements/all.h++ \
	elements/ElementFactory.h++ \
	elements/BaseElement.h++ \
	elements/Triangle3.h++ \
	elements/Triangle6.h++ \
	elements/Quadrangle4.h++ \
	elements/Quadrangle8.h++ \
	elements/Quadrangle9.h++ \
	elements/Hexahedron8.h++ \
	elements/Hexahedron20.h++ \
	elements/Hexahedron27.h++ \
	elements/Tetrahedron4.h++ \
	elements/Tetrahedron10.h++ \
	elements/Prism6.h++ \
	elements/Prism18.h++ \
	SurfaceLoadOperators/ConcentricLoad.h++	\
	SurfaceLoadOperators/ConstantLoad.h++ \
	SurfaceLoadOperators/SurfaceLoadOperator.h++ \
	SurfaceLoadOperators/SurfaceNormalLoad.h++ \
	Analysis.h++ \
	LinearAnalysis.h++ \
	AnalysisResult.h++\
	ElementResults/ElementResultsFactory.h++ \
	ElementResults/Stresses.h++ \
	ElementResults/ResultsRanges.h++ \
	ElementResults/Strains.h++ \
	ElementResults/ElementResults.h++ \
	solvers/Solver.h++ \
	solvers/CholeskySolver.h++ \
	solvers/CGSolver.h++ \
	solvers/UmfpackSolver.h++ \
	Surface.h++ \
	solvers/*.h++ \
	parsers/fem_msh.h++ lex.msh_yy.h \
	parsers/parser.h++ \
	parsers/MshParser.h++ \
	parsers/json.h \
	parsers/FemJsonParser.h++

SOURCES = Group.c++ \
	Model.c++ \
	Node.c++ \
	GlobalDof.c++ \
	GlobalDofMap.c++ \
	Element.c++ \
	Material.c++ \
	LoadPattern.c++ \
	NodalLoad.c++ \
	NodalDisplacement.c++ \
	Point.c++ \
	Point2D.c++ \
	NodeRestrictions.c++ \
	DomainLoad.c++ \
	SurfaceLoad.c++\
	ElementGroup.c++ \
	NodeGroup.c++ \
	elements/ElementFactory.c++ \
	elements/BaseElement.c++ \
	Analysis.c++ \
	LinearAnalysis.c++ \
	SurfaceLoadOperators/ConcentricLoad.c++	\
	SurfaceLoadOperators/ConstantLoad.c++ \
	SurfaceLoadOperators/SurfaceLoadOperator.c++ \
	SurfaceLoadOperators/SurfaceNormalLoad.c++ \
	Surface.c++ \
	parsers/fem_msh.c++ lex.msh_yy.c++ \
	parsers/parser.c++ \
	parsers/MshParser.c++ \
	parsers/json.c \
	parsers/FemJsonParser.c++


FemJsonParserRe2c.target = parsers/FemJsonParser.c++
FemJsonParserRe2c.commands = re2c -o parsers/FemJsonParser.c++ parsers/FemJsonParser.c++.re2c
FemJsonParserRe2c.depends = parsers/FemJsonParser.c++.re2c
FemJsonParserRe2c.output = parsers/FemJsonParser.c++

MshParserRe2c.target = parsers/MshParser.c++
MshParserRe2c.commands = re2c -o parsers/MshParser.c++ parsers/MshParser.c++.re2c
MshParserRe2c.depends = parsers/MshParser.c++.re2c
MshParserRe2c.output = parsers/MshParser.c++

Flex.target = lex.msh_yy.h 
Flex.commands = flex --header-file=lex.msh_yy.h -o lex.msh_yy.c++ msh.l
Flex.depends = msh.l 
Flex.output = lex.msh_yy.c++ lex.msh_yy.h

Bison.name = Bison ${QMAKE_FILE_IN}
Bison.input = msh.y
Bison.output = msh.tab.c msh.tab.h
Bison.commands = bison -d --debug msh.y -o ${QMAKE_FILE_PATH}/
Bison.depends = msh.y lex.msh_yy.h 

BisonCompile.input = msh.tab.c
BisonCompile.output = msh.tab.o
BisonCompile.commands = g++ -c msh.tab.c $(INCPATH)

QMAKE_CLEAN += lex.msh_yy.h lex.msh_yy.c++ msh.tab.c msh.tab.h msh.tab.o

QMAKE_EXTRA_TARGETS += FemJsonParserRe2c MshParserRe2c Flex Bison BisonCompile 
