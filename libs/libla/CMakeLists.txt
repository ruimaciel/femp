cmake_minimum_required(VERSION 3.10)

project(libla
    LANGUAGES CXX
    VERSION 0.1.0
    )

list(APPEND CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake")

find_package(suitesparse MODULE REQUIRED)

set( libla_INCLUDES
    include/la/VectorStorage/SparseCS.hpp
    include/la/VectorStorage/Dense.hpp
    include/la/DenseStatic.hpp
    include/la/operations/mv.hpp
    include/la/operations/vv.hpp
    include/la/output.hpp
    include/la/MatrixStorage/LowerTriangular.hpp
    include/la/MatrixStorage/SparseCRS.hpp
    include/la/MatrixStorage/Opengl.hpp
    include/la/MatrixStorage/SparseDOK.hpp
    include/la/MatrixStorage/SparseCCS.hpp
    include/la/MatrixStorage/Dense.hpp
    include/la/MatrixStorage/Diagonal.hpp
    include/la/Matrix.hpp
    include/la/Operations.hpp
    include/la/ProgressIndicatorStrategy.hpp
    include/la/vector/DenseStatic.hpp
    include/la/solvers/substitution.hpp
    include/la/solvers/CG.hpp
    include/la/solvers/SolverReturnCodes.hpp
    include/la/solvers/Umfpack.hpp
    include/la/solvers/Cholesky.hpp
    include/la/Vector.hpp
    )

set( libla_HEADERS
    )

set( libla_SOURCES
    src/solvers/Umfpack.cpp
    )

add_library(libla
    ${libla_INCLUDES}
    ${libla_HEADERS}
    ${libla_SOURCES}
    )

target_link_libraries(libla
    umfpack
    )

target_include_directories(libla
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include
    )

set_target_properties(libla PROPERTIES
	CXX_STANDARD 14
    CXX_EXTENSIONS OFF
    )

option(RUN_TESTS "Runs tests" ON)
