include(../defaults.pri)

TEMPLATE = lib

CONFIG += staticlib

OBJECTS_DIR += $${BUILD_DIR}/libfemp
DESTDIR = $${BUILD_DIR}

INCLUDEPATH += /usr/include/eigen2 /usr/include/suitesparse $${LIBFEMP_SRC}

#LIBS += -lumfpack -lblas -lamd -lGLU -L$${PWD}/../libla -llibla
LIBS += -lumfpack -lblas -lamd -lGLU -llibla


HEADERS = Group.h++ \
	Model.h++ \
	Node.h++ \
	Element.h++ \
	Material.h++ \
	LoadPattern.h++ \
	NodalLoad.h++ \
	NodalDisplacement.h++ \
	point.h++ \
	NodeRestrictions.h++ \
	DomainLoad.h++ \
	SurfaceLoad.h++ \
	ElementGroup.h++ \
	NodeGroup.h++ \
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
	SurfaceLoadOperators/*.h++ \
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
	solvers/*.h++

SOURCES = Group.c++ \
	Model.c++ \
	Node.c++ \
	Element.c++ \
	Material.c++ \
	LoadPattern.c++ \
	NodalLoad.c++ \
	NodalDisplacement.c++ \
	point.c++ \
	NodeRestrictions.c++ \
	DomainLoad.c++ \
	SurfaceLoad.c++\
	ElementGroup.c++ \
	NodeGroup.c++ \
	Analysis.c++ \
	SurfaceLoadOperators/*.c++ \
	Surface.c++ 

