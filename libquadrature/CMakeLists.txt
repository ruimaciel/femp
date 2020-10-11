cmake_minimum_required(VERSION 3.10) # due to googletest

project(libquadrature
    LANGUAGES CXX
    VERSION 0.1.0
    )

set(libquadrature_INCLUDES
    include/quadrature_rules/Line.h++
    include/quadrature_rules/Prism.h++
    include/quadrature_rules/Tetrahedron.h++
    include/quadrature_rules/QuadraturePoint.h++
    include/quadrature_rules/Triangle.h++
    include/quadrature_rules/SurfaceRule.h++
    include/quadrature_rules/Quadrangle.h++
    include/quadrature_rules/Hexahedron.h++
    include/quadrature_rules/VolumeRule.h++
    )

set(libquadrature_SOURCES
    src/Line.c++
    src/Quadrangle.c++
    src/Hexahedron.c++
    src/Prism.c++
    src/Triangle.c++
    src/SurfaceRule.c++
    src/Tetrahedron.c++
    )

add_library(libquadrature
    ${libquadrature_INCLUDES}
    ${libquadrature_SOURCES}
    )

set_target_properties(libquadrature PROPERTIES
    CXX_STANDARD 11
    CXX_EXTENSIONS OFF
    )

target_include_directories(libquadrature
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src
    )

option(RUN_TESTS ON "Run libquadrature's tests")
if(RUN_TESTS)
    add_subdirectory(tests)
endif()
