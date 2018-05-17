include(../defaults.pri)

TEMPLATE = lib

CONFIG += staticlib
CONFIG += object_parallel_to_source
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
        NodalDisplacement.h++ \
        Point2D.h++ \
        NodeRestrictions.h++ \
        quadrature_rules/QuadraturePoint.h++ \
        quadrature_rules/Line.h++ \
        quadrature_rules/Quadrangle.h++ \
        quadrature_rules/Triangle.h++ \
        quadrature_rules/Hexahedron.h++ \
        quadrature_rules/Tetrahedron.h++ \
        quadrature_rules/Prism.h++ \
        loads/NodalLoad.h++ \
        loads/DomainLoad.h++ \
        loads/SurfaceLoad.h++ \
        ElementGroup.h++ \
        NodeGroup.h++ \
        elements/all.h++ \
        elements/ElementFactory.h++ \
        elements/BaseElement.h++ \
        elements/HexahedronFamily.h++ \
        elements/Hexahedron8.h++ \
        elements/Hexahedron20.h++ \
        elements/Hexahedron27.h++ \
        elements/TetrahedronFamily.h++ \
        elements/Tetrahedron4.h++ \
        elements/Tetrahedron10.h++ \
        elements/PrismFamily.h++ \
        elements/Prism6.h++ \
        elements/Prism18.h++ \
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
        parsers/fem_msh.h++ \
        lex.msh_yy.h++ \
        parsers/parser.h++ \
        parsers/MshParser.h++ \
        parsers/json.h \
        parsers/FemJsonParser.h++ \
	export/JsonExporter.h++ \
	loads/QuadrangleFamily.h++ \
	loads/Quadrangle4.h++ \
	loads/Quadrangle8.h++ \
	loads/Quadrangle9.h++ \
	loads/TriangleFamily.h++ \
	loads/Triangle3.h++ \
	loads/Triangle6.h++ \
	loads/Triangle10.h++ \
    Point3D.h++ \
    quadrature_rules/VolumeRule.h++

SOURCES = Group.c++ \
	Model.c++ \
        Node.c++ \
        GlobalDof.c++ \
        GlobalDofMap.c++ \
        Element.c++ \
        Material.c++ \
        LoadPattern.c++ \
        NodalDisplacement.c++ \
        Point2D.c++ \
        NodeRestrictions.c++ \
        quadrature_rules/Line.c++ \
        quadrature_rules/Quadrangle.c++ \
        quadrature_rules/Triangle.c++ \
        quadrature_rules/Hexahedron.c++ \
        quadrature_rules/Tetrahedron.c++ \
        quadrature_rules/Prism.c++ \
        loads/NodalLoad.c++ \
        loads/DomainLoad.c++ \
        loads/SurfaceLoad.c++\
        ElementGroup.c++ \
        NodeGroup.c++ \
        elements/ElementFactory.c++ \
        elements/BaseElement.c++ \
        elements/HexahedronFamily.c++ \
        elements/Hexahedron8.c++ \
        elements/Hexahedron20.c++ \
        elements/Hexahedron27.c++ \
        elements/TetrahedronFamily.c++ \
        elements/Tetrahedron4.c++ \
        elements/Tetrahedron10.c++ \
        elements/PrismFamily.c++ \
        elements/Prism6.c++ \
        elements/Prism15.c++ \
        elements/Prism18.c++ \
        Analysis.c++ \
        LinearAnalysis.c++ \
        AnalysisResult.c++\
        ElementResults/ElementResultsFactory.c++ \
        ElementResults/ElementResults.c++ \
        SurfaceLoadOperators/ConstantLoad.c++ \
        SurfaceLoadOperators/SurfaceLoadOperator.c++ \
        SurfaceLoadOperators/SurfaceNormalLoad.c++ \
        Surface.c++ \
        parsers/fem_msh.c++ \
        lex.msh_yy.c++ \
        parsers/parser.c++ \
        parsers/MshParser.c++ \
        parsers/json.c \
        parsers/FemJsonParser.c++ \
	export/JsonExporter.c++ \
	loads/QuadrangleFamily.c++ \
	loads/Quadrangle4.c++ \
	loads/Quadrangle8.c++ \
	loads/Quadrangle9.c++ \
	loads/TriangleFamily.c++ \
	loads/Triangle3.c++ \
	loads/Triangle6.c++ \
	loads/Triangle10.c++ \
    Point3D.c++


FemJsonParserRe2c.target = parsers/FemJsonParser.c++
FemJsonParserRe2c.commands = re2c -o parsers/FemJsonParser.c++ parsers/FemJsonParser.c++.re2c
FemJsonParserRe2c.depends = parsers/FemJsonParser.c++.re2c
FemJsonParserRe2c.output = parsers/FemJsonParser.c++

MshParserRe2c.target = parsers/MshParser.c++
MshParserRe2c.commands = re2c -o parsers/MshParser.c++ parsers/MshParser.c++.re2c
MshParserRe2c.depends = parsers/MshParser.c++.re2c
MshParserRe2c.output = parsers/MshParser.c++

FLEXINPUT = msh.l
Flex.input = FLEXINPUT
Flex.output = lex.msh_yy.c++ lex.msh_yy.h
Flex.depends = msh.l
Flex.commands = flex --header-file=lex.msh_yy.h++ -o lex.msh_yy.c++ ${FLEXINPUT}
Flex.name = flex

BISONINPUT = msh.y
Bison.name = Bison ${QMAKE_FILE_IN}
Bison.input = BISONINPUT
Bison.output = msh.tab.c msh.tab.h
Bison.depends = msh.y
Bison.commands = bison -d --debug msh.y -o ${QMAKE_FILE_PATH}/

BisonCompile.input = msh.tab.c
BisonCompile.output = msh.tab.o
BisonCompile.commands = g++ -c msh.tab.c $(INCPATH)

QMAKE_CLEAN += lex.msh_yy.h++ lex.msh_yy.c++ msh.tab.c msh.tab.h msh.tab.o

QMAKE_EXTRA_TARGETS += FemJsonParserRe2c MshParserRe2c Flex Bison BisonCompile
