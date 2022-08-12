cmake_minimum_required(VERSION 3.1)

project(libfemp
	LANGUAGES CXX
	VERSION 0.1.0
	)

option(USES_RE2C "Uses re2c to regenerate the lexer files")
if(USES_RE2C)
	message(STATUS "Adding re2c custom rules")
	find_program(RE2C re2c REQUIRED)

	add_custom_command( OUTPUT ${CMAKE_CURRENT_SOURCE_DIR}/src/io/import/FemJsonParser.c++
		DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/src/io/import/FemJsonParser.c++.re2c ${CMAKE_CURRENT_SOURCE_DIR}/src/io/import/FemJsonParser.h++
		COMMAND ${RE2C}
		ARGS -i -T -o ${CMAKE_CURRENT_SOURCE_DIR}/src/io/import/FemJsonParser.c++ ${CMAKE_CURRENT_SOURCE_DIR}/src/io/import/FemJsonParser.c++.re2c
		COMMENT "Generating re2c files"
		)
else(USES_RE2C)
	message(STATUS "Skipping re2c custom rules")
endif()

add_subdirectory(io)
add_subdirectory(mesh)

set(libfemp_INCLUDES
	include/libfemp/Point2D.h++
	include/libfemp/SurfaceLoadOperators/SurfaceNormalLoad.h++
	include/libfemp/SurfaceLoadOperators/SurfaceLoadOperator.h++
	include/libfemp/SurfaceLoadOperators/ConstantLoad.h++
	include/libfemp/ElementResults/ElementResultsFactory.h++
	include/libfemp/ElementResults/Stresses.h++
	include/libfemp/ElementResults/ResultsRanges.h++
	include/libfemp/ElementResults/Strains.h++
	include/libfemp/ElementResults/ElementResults.h++
	include/libfemp/Node.h++
	include/libfemp/Material.h++
	include/libfemp/Point3D.h++
	include/libfemp/elements/Prism6.h++
	include/libfemp/elements/Tetrahedron10.h++
	include/libfemp/elements/Hexahedron20.h++
	include/libfemp/elements/Tetrahedron4.h++
	include/libfemp/elements/all.h++
	include/libfemp/elements/Prism18.h++
	include/libfemp/elements/ElementFactory.h++
	include/libfemp/elements/Prism15.h++
	include/libfemp/elements/Hexahedron27.h++
	include/libfemp/elements/HexahedronFamily.h++
	include/libfemp/elements/TetrahedronFamily.h++
	include/libfemp/elements/BaseElement.h++
	include/libfemp/elements/Hexahedron8.h++
	include/libfemp/elements/PrismFamily.h++
	include/libfemp/ElementGroup.h++
	include/libfemp/io/export/JsonExporter.h++
	include/libfemp/LoadPattern.h++
	include/libfemp/Group.h++
	include/libfemp/GlobalDof.h++
	include/libfemp/Equation.h++
	include/libfemp/NodalDisplacement.h++
	include/libfemp/Analysis.h++
	include/libfemp/NodeRestrictions.h++
	include/libfemp/Element.h++
	include/libfemp/LinearAnalysis.h++
	include/libfemp/NodeGroup.h++
	include/libfemp/io/import/Parser.h++
	include/libfemp/io/import/ModelImporterFactory.h++
	include/libfemp/solvers/CholeskySolver.h++
	include/libfemp/solvers/CGSolver.h++
	include/libfemp/solvers/DenseCholeskySolver.h++
	include/libfemp/solvers/UmfpackSolver.h++
	include/libfemp/solvers/Solver.h++
	include/libfemp/AnalysisResult.h++
	include/libfemp/FemException.h++
	include/libfemp/GlobalDofMap.h++
	include/libfemp/loads/Triangle6.h++
	include/libfemp/loads/Quadrangle9.h++
	include/libfemp/loads/DomainLoad.h++
	include/libfemp/loads/Triangle3.h++
	include/libfemp/loads/Triangle10.h++
	include/libfemp/loads/SurfaceLoad.h++
	include/libfemp/loads/Quadrangle8.h++
	include/libfemp/loads/NodalLoad.h++
	include/libfemp/loads/Quadrangle4.h++
	include/libfemp/loads/QuadrangleFamily.h++
	include/libfemp/loads/TriangleFamily.h++
	include/libfemp/Surface.h++
	include/libfemp/Model.h++
	)

set(libfemp_HEADERS
	src/io/import/FemJsonParser.h++
	src/io/import/MshParser.h++
	)

set(libfemp_SOURCES
	src/NodeGroup.c++
	src/SurfaceLoadOperators/ConstantLoad.c++
	src/SurfaceLoadOperators/SurfaceNormalLoad.c++
	src/ElementResults/ElementResults.c++
	src/ElementResults/ElementResultsFactory.c++
	src/Point3D.c++
	src/Point2D.c++
	src/AnalysisResult.c++
	src/ElementGroup.c++
	src/Element.c++
	src/elements/Hexahedron8.c++
	src/elements/Tetrahedron10.c++
	src/elements/TetrahedronFamily.c++
	src/elements/Prism18.c++
	src/elements/Hexahedron20.c++
	src/elements/ElementFactory.c++
	src/elements/BaseElement.c++
	src/elements/Prism6.c++
	src/elements/HexahedronFamily.c++
	src/elements/Tetrahedron4.c++
	src/elements/Prism15.c++
	src/elements/Hexahedron27.c++
	src/elements/PrismFamily.c++
	src/io/export/JsonExporter.c++
	src/GlobalDof.c++
	src/Analysis.c++
	src/Equation.c++
	src/NodeRestrictions.c++
	src/Material.c++
	src/Model.c++
	src/LinearAnalysis.c++
	src/io/import/FemJsonParser.c++
	src/io/import/Parser.c++
	src/io/import/ModelImporterFactory.c++
	src/io/import/MshParser.c++
	src/FemException.c++
	src/GlobalDofMap.c++
	src/Group.c++
	src/Surface.c++
	src/NodalDisplacement.c++
	src/loads/SurfaceLoad.c++
	src/loads/NodalLoad.c++
	src/loads/TriangleFamily.c++
	src/loads/QuadrangleFamily.c++
	src/loads/DomainLoad.c++
	src/loads/Triangle10.c++
	src/loads/Quadrangle9.c++
	src/loads/Triangle3.c++
	src/loads/Quadrangle4.c++
	src/loads/Quadrangle8.c++
	src/loads/Triangle6.c++
	src/LoadPattern.c++
	src/Node.c++
	)

add_library(libfemp
	${libfemp_INCLUDES}
	${libfemp_HEADERS}
	${libfemp_SOURCES}
	)

add_dependencies(libfemp
    libfemp_mesh
    libfemp_io
    )

find_package(Eigen3 3.3 REQUIRED)


target_link_libraries(libfemp
	libla
    libquadrature
	Eigen3::Eigen
    libfemp_io
    libfemp_mesh
	)

set_target_properties(libfemp PROPERTIES
	CXX_STANDARD 14
	CXX_EXTENSIONS OFF
	)

target_include_directories(libfemp
	PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include
	PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src
	)

if(RUN_TESTS)
	enable_testing()
	add_subdirectory(tests)
endif()
