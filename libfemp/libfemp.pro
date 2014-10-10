include(../defaults.pri)

TEMPLATE = lib

CONFIG += staticlib

OBJECTS_DIR += ./build

INCLUDEPATH += /usr/include/eigen2 /usr/include/suitesparse $${LIBFEMP_SRC}

LIBS += -lumfpack -lblas -lamd -lGLU -L$${PWD}/../libla -llibla


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
	solvers/Solver.h++ \
	solvers/CholeskySolver.h++ \
	solvers/CGSolver.h++ \
	solvers/UmfpackSolver.h++ \
	Surface.h++ \
	lalib/Matrix.h++ \
	lalib/Vector.h++ \
	lalib/solvers/*.h++ \
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
	SurfaceLoadOperators/*.c++ \
	Surface.c++ 

