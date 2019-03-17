include(../defaults.pri)

TEMPLATE = lib

CONFIG += staticlib
CONFIG += object_parallel_to_source
CONFIG -= qt

OBJECTS_DIR += $${BUILD_DIR}/libfemp
DESTDIR = $${BUILD_DIR}

INCLUDEPATH += \
    /usr/include/eigen3 \
    ./include \
    ../libla/include

LIBS += -llibla


HEADERS = Group.h++ \
    include/libfemp/Model.h++ \
    include/libfemp/Node.h++ \
    include/libfemp/GlobalDof.h++ \
    include/libfemp/GlobalDofMap.h++ \
    include/libfemp/Element.h++ \
    include/libfemp/Material.h++ \
    include/libfemp/LoadPattern.h++ \
    include/libfemp/NodalDisplacement.h++ \
    include/libfemp/Point2D.h++ \
    include/libfemp/NodeRestrictions.h++ \
    include/libfemp/quadrature_rules/QuadraturePoint.h++ \
    include/libfemp/quadrature_rules/Line.h++ \
    include/libfemp/quadrature_rules/Quadrangle.h++ \
    include/libfemp/quadrature_rules/Triangle.h++ \
    include/libfemp/quadrature_rules/Hexahedron.h++ \
    include/libfemp/quadrature_rules/Tetrahedron.h++ \
    include/libfemp/quadrature_rules/Prism.h++ \
    include/libfemp/loads/NodalLoad.h++ \
    include/libfemp/loads/DomainLoad.h++ \
    include/libfemp/loads/SurfaceLoad.h++ \
    include/libfemp/ElementGroup.h++ \
    include/libfemp/NodeGroup.h++ \
    include/libfemp/elements/all.h++ \
    include/libfemp/elements/ElementFactory.h++ \
    include/libfemp/elements/BaseElement.h++ \
    include/libfemp/elements/HexahedronFamily.h++ \
    include/libfemp/elements/Hexahedron8.h++ \
    include/libfemp/elements/Hexahedron20.h++ \
    include/libfemp/elements/Hexahedron27.h++ \
    include/libfemp/elements/TetrahedronFamily.h++ \
    include/libfemp/elements/Tetrahedron4.h++ \
    include/libfemp/elements/Tetrahedron10.h++ \
    include/libfemp/elements/PrismFamily.h++ \
    include/libfemp/elements/Prism6.h++ \
    include/libfemp/elements/Prism18.h++ \
    include/libfemp/SurfaceLoadOperators/ConstantLoad.h++ \
    include/libfemp/SurfaceLoadOperators/SurfaceLoadOperator.h++ \
    include/libfemp/SurfaceLoadOperators/SurfaceNormalLoad.h++ \
    include/libfemp/Analysis.h++ \
    include/libfemp/LinearAnalysis.h++ \
    include/libfemp/AnalysisResult.h++\
    include/libfemp/ElementResults/ElementResultsFactory.h++ \
    include/libfemp/ElementResults/Stresses.h++ \
    include/libfemp/ElementResults/ResultsRanges.h++ \
    include/libfemp/ElementResults/Strains.h++ \
    include/libfemp/ElementResults/ElementResults.h++ \
    include/libfemp/solvers/Solver.h++ \
    include/libfemp/solvers/CholeskySolver.h++ \
    include/libfemp/solvers/CGSolver.h++ \
    include/libfemp/solvers/UmfpackSolver.h++ \
    include/libfemp/Surface.h++ \
    include/libfemp/solvers/*.h++ \
    include/libfemp/src/parsers/fem_msh.h++ \
    include/libfemp/src/parsers/parser.h++ \
    include/libfemp/src/parsers/MshParser.h++ \
    include/libfemp/src/parsers/json.h \
    include/libfemp/src/parsers/FemJsonParser.h++ \
    include/libfemp/export/JsonExporter.h++ \
    include/libfemp/loads/QuadrangleFamily.h++ \
    include/libfemp/loads/Quadrangle4.h++ \
    include/libfemp/loads/Quadrangle8.h++ \
    include/libfemp/loads/Quadrangle9.h++ \
    include/libfemp/loads/TriangleFamily.h++ \
    include/libfemp/loads/Triangle3.h++ \
    include/libfemp/loads/Triangle6.h++ \
    include/libfemp/loads/Triangle10.h++ \
    include/libfemp/Point3D.h++ \
    include/libfemp/quadrature_rules/VolumeRule.h++ \
    include/libfemp/quadrature_rules/SurfaceRule.h++ \
    include/libfemp/Equation.h++ \
    src/lex.msh_yy.h++

SOURCES = \
    src/Group.c++ \
    src/Model.c++ \
    src/Node.c++ \
    src/GlobalDof.c++ \
    src/GlobalDofMap.c++ \
    src/Element.c++ \
    src/Material.c++ \
    src/LoadPattern.c++ \
    src/NodalDisplacement.c++ \
    src/Point2D.c++ \
    src/NodeRestrictions.c++ \
    src/quadrature_rules/Line.c++ \
    src/quadrature_rules/Quadrangle.c++ \
    src/quadrature_rules/Triangle.c++ \
    src/quadrature_rules/Hexahedron.c++ \
    src/quadrature_rules/Tetrahedron.c++ \
    src/quadrature_rules/Prism.c++ \
    src/loads/NodalLoad.c++ \
    src/loads/DomainLoad.c++ \
    src/loads/SurfaceLoad.c++\
    src/ElementGroup.c++ \
    src/NodeGroup.c++ \
    src/elements/ElementFactory.c++ \
    src/elements/BaseElement.c++ \
    src/elements/HexahedronFamily.c++ \
    src/elements/Hexahedron8.c++ \
    src/elements/Hexahedron20.c++ \
    src/elements/Hexahedron27.c++ \
    src/elements/TetrahedronFamily.c++ \
    src/elements/Tetrahedron4.c++ \
    src/elements/Tetrahedron10.c++ \
    src/elements/PrismFamily.c++ \
    src/elements/Prism6.c++ \
    src/elements/Prism15.c++ \
    src/elements/Prism18.c++ \
    src/Analysis.c++ \
    src/LinearAnalysis.c++ \
    src/AnalysisResult.c++\
    src/ElementResults/ElementResultsFactory.c++ \
    src/ElementResults/ElementResults.c++ \
    src/SurfaceLoadOperators/ConstantLoad.c++ \
    src/SurfaceLoadOperators/SurfaceNormalLoad.c++ \
    src/Surface.c++ \
    src/parsers/fem_msh.c++ \
    src/lex.msh_yy.c++ \
    src/parsers/parser.c++ \
    src/parsers/MshParser.c++ \
    src/parsers/json.c \
    src/parsers/FemJsonParser.c++ \
    src/export/JsonExporter.c++ \
    src/loads/QuadrangleFamily.c++ \
    src/loads/Quadrangle4.c++ \
    src/loads/Quadrangle8.c++ \
    src/loads/Quadrangle9.c++ \
    src/loads/TriangleFamily.c++ \
    src/loads/Triangle3.c++ \
    src/loads/Triangle6.c++ \
    src/loads/Triangle10.c++ \
    src/Point3D.c++ \
    src/quadrature_rules/SurfaceRule.c++ \
    src/Equation.c++


FemJsonParserRe2c.target = src/parsers/FemJsonParser.c++
FemJsonParserRe2c.commands = re2c -o src/parsers/FemJsonParser.c++ src/parsers/FemJsonParser.c++.re2c
FemJsonParserRe2c.depends = src/parsers/FemJsonParser.c++.re2c
FemJsonParserRe2c.output = src/parsers/FemJsonParser.c++

MshParserRe2c.target = src/parsers/MshParser.c++
MshParserRe2c.commands = re2c -o src/parsers/MshParser.c++ src/parsers/MshParser.c++.re2c
MshParserRe2c.depends = src/parsers/MshParser.c++.re2c
MshParserRe2c.output = src/parsers/MshParser.c++

FLEXINPUT = src/msh.l
Flex.input = FLEXINPUT
Flex.output = src/lex.msh_yy.c++ src/lex.msh_yy.h
Flex.depends = src/msh.l
Flex.commands = flex --header-file=src/lex.msh_yy.h++ -o src/lex.msh_yy.c++ src/msh.l
Flex.name = flex

BISONINPUT = src/msh.y
Bison.name = Bison ${QMAKE_FILE_IN}
Bison.input = BISONINPUT
Bison.output = src/msh.tab.c src/msh.tab.h
Bison.depends = src/msh.y
Bison.commands = bison -d --debug src/msh.y -o ${QMAKE_FILE_PATH}/src/msh.c

BisonCompile.input = msh.tab.c
BisonCompile.output = msh.tab.o
BisonCompile.commands = g++ -c msh.tab.c $(INCPATH)

QMAKE_CLEAN += lex.msh_yy.h++ lex.msh_yy.c++ msh.tab.c msh.tab.h msh.tab.o

QMAKE_EXTRA_TARGETS += FemJsonParserRe2c MshParserRe2c Flex Bison BisonCompile
