cmake_minimum_required(VERSION 3.1)

project(libla
    LANGUAGES CXX
    VERSION 0.1.0
    )

list(APPEND CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake")

find_package(suitesparse MODULE REQUIRED)

set( libla_INCLUDES
    include/la/VectorStorage/SparseCS.h++
    include/la/VectorStorage/Dense.h++
    include/la/DenseStatic.h++
    include/la/operations/mv.h++
    include/la/operations/vv.h++
    include/la/output.h++
    include/la/MatrixStorage/LowerTriangular.h++
    include/la/MatrixStorage/SparseCRS.h++
    include/la/MatrixStorage/Opengl.h++
    include/la/MatrixStorage/SparseDOK.h++
    include/la/MatrixStorage/SparseCCS.h++
    include/la/MatrixStorage/Dense.h++
    include/la/MatrixStorage/Diagonal.h++
    include/la/Matrix.h++
    include/la/Operations.h++
    include/la/ProgressIndicatorStrategy.h++
    include/la/vector/DenseStatic.h++
    include/la/solvers/substitution.h++
    include/la/solvers/CG.h++
    include/la/solvers/SolverReturnCodes.h++
    include/la/solvers/Umfpack.h++
    include/la/solvers/Cholesky.h++
    include/la/Vector.h++
    )

set( libla_HEADERS
    )

set( libla_SOURCES
    src/solvers/Umfpack.c++
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
