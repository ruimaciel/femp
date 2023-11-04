cmake_minimum_required(VERSION 3.1)

project(libfemp
	LANGUAGES CXX
	VERSION 0.1.0
	)

option(USES_RE2C "Uses re2c to regenerate the lexer files")
if(USES_RE2C)
	message(STATUS "Adding re2c custom rules")
	find_program(RE2C re2c REQUIRED)

	add_custom_command( OUTPUT ${CMAKE_CURRENT_SOURCE_DIR}/src/io/import/FemJsonParser.cpp
		DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/src/io/import/FemJsonParser.cpp.re2c ${CMAKE_CURRENT_SOURCE_DIR}/src/io/import/FemJsonParser.hpp
		COMMAND ${RE2C}
		ARGS -i -T -o ${CMAKE_CURRENT_SOURCE_DIR}/src/io/import/FemJsonParser.cpp ${CMAKE_CURRENT_SOURCE_DIR}/src/io/import/FemJsonParser.cpp.re2c
		COMMENT "Generating re2c files"
		)
else(USES_RE2C)
	message(STATUS "Skipping re2c custom rules")
endif()

add_subdirectory(io)
add_subdirectory(mesh)

set(libfemp_INCLUDES
	include/libfemp/Point2D.hpp
	include/libfemp/SurfaceLoadOperators/SurfaceNormalLoad.hpp
	include/libfemp/SurfaceLoadOperators/SurfaceLoadOperator.hpp
	include/libfemp/SurfaceLoadOperators/ConstantLoad.hpp
	include/libfemp/ElementResults/ElementResultsFactory.hpp
	include/libfemp/ElementResults/Stresses.hpp
	include/libfemp/ElementResults/ResultsRanges.hpp
	include/libfemp/ElementResults/Strains.hpp
	include/libfemp/ElementResults/ElementResults.hpp
	include/libfemp/Node.hpp
	include/libfemp/Material.hpp
	include/libfemp/Point3D.hpp
	include/libfemp/elements/Prism6.hpp
	include/libfemp/elements/Tetrahedron10.hpp
	include/libfemp/elements/Hexahedron20.hpp
	include/libfemp/elements/Tetrahedron4.hpp
	include/libfemp/elements/all.hpp
	include/libfemp/elements/Prism18.hpp
	include/libfemp/elements/ElementFactory.hpp
	include/libfemp/elements/Prism15.hpp
	include/libfemp/elements/Hexahedron27.hpp
	include/libfemp/elements/HexahedronFamily.hpp
	include/libfemp/elements/TetrahedronFamily.hpp
	include/libfemp/elements/BaseElement.hpp
	include/libfemp/elements/Hexahedron8.hpp
	include/libfemp/elements/PrismFamily.hpp
	include/libfemp/ElementGroup.hpp
	include/libfemp/io/export/JsonExporter.hpp
	include/libfemp/LoadPattern.hpp
	include/libfemp/Group.hpp
	include/libfemp/GlobalDof.hpp
	include/libfemp/Equation.hpp
	include/libfemp/NodalDisplacement.hpp
	include/libfemp/Analysis.hpp
	include/libfemp/NodeRestrictions.hpp
	include/libfemp/Element.hpp
	include/libfemp/LinearAnalysis.hpp
	include/libfemp/NodeGroup.hpp
	include/libfemp/io/import/Parser.hpp
	include/libfemp/io/import/ModelImporterFactory.hpp
	include/libfemp/solvers/CholeskySolver.hpp
	include/libfemp/solvers/CGSolver.hpp
	include/libfemp/solvers/DenseCholeskySolver.hpp
	include/libfemp/solvers/UmfpackSolver.hpp
	include/libfemp/solvers/Solver.hpp
	include/libfemp/AnalysisResult.hpp
	include/libfemp/FemException.hpp
	include/libfemp/GlobalDofMap.hpp
	include/libfemp/loads/Triangle6.hpp
	include/libfemp/loads/Quadrangle9.hpp
	include/libfemp/loads/DomainLoad.hpp
	include/libfemp/loads/Triangle3.hpp
	include/libfemp/loads/Triangle10.hpp
	include/libfemp/loads/SurfaceLoad.hpp
	include/libfemp/loads/Quadrangle8.hpp
	include/libfemp/loads/NodalLoad.hpp
	include/libfemp/loads/Quadrangle4.hpp
	include/libfemp/loads/QuadrangleFamily.hpp
	include/libfemp/loads/TriangleFamily.hpp
	include/libfemp/Surface.hpp
	include/libfemp/Model.hpp
	)

set(libfemp_HEADERS
	src/io/import/FemJsonParser.hpp
	src/io/import/MshParser.hpp
	)

set(libfemp_SOURCES
	src/NodeGroup.cpp
	src/SurfaceLoadOperators/ConstantLoad.cpp
	src/SurfaceLoadOperators/SurfaceNormalLoad.cpp
	src/ElementResults/ElementResults.cpp
	src/ElementResults/ElementResultsFactory.cpp
	src/Point3D.cpp
	src/Point2D.cpp
	src/AnalysisResult.cpp
	src/ElementGroup.cpp
	src/Element.cpp
	src/elements/Hexahedron8.cpp
	src/elements/Tetrahedron10.cpp
	src/elements/TetrahedronFamily.cpp
	src/elements/Prism18.cpp
	src/elements/Hexahedron20.cpp
	src/elements/ElementFactory.cpp
	src/elements/BaseElement.cpp
	src/elements/Prism6.cpp
	src/elements/HexahedronFamily.cpp
	src/elements/Tetrahedron4.cpp
	src/elements/Prism15.cpp
	src/elements/Hexahedron27.cpp
	src/elements/PrismFamily.cpp
	src/io/export/JsonExporter.cpp
	src/GlobalDof.cpp
	src/Analysis.cpp
	src/Equation.cpp
	src/NodeRestrictions.cpp
	src/Material.cpp
	src/Model.cpp
	src/LinearAnalysis.cpp
	src/io/import/FemJsonParser.cpp
	src/io/import/Parser.cpp
	src/io/import/ModelImporterFactory.cpp
	src/io/import/MshParser.cpp
	src/FemException.cpp
	src/GlobalDofMap.cpp
	src/Group.cpp
	src/Surface.cpp
	src/NodalDisplacement.cpp
	src/loads/SurfaceLoad.cpp
	src/loads/NodalLoad.cpp
	src/loads/TriangleFamily.cpp
	src/loads/QuadrangleFamily.cpp
	src/loads/DomainLoad.cpp
	src/loads/Triangle10.cpp
	src/loads/Quadrangle9.cpp
	src/loads/Triangle3.cpp
	src/loads/Quadrangle4.cpp
	src/loads/Quadrangle8.cpp
	src/loads/Triangle6.cpp
	src/LoadPattern.cpp
	src/Node.cpp
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
	Boost::headers
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