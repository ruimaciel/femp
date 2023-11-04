cmake_minimum_required(VERSION 3.10) # due to googletest

project(libquadrature
    LANGUAGES CXX
    VERSION 0.1.0
    )

set(libquadrature_INCLUDES
    include/quadrature_rules/Line.hpp
    include/quadrature_rules/Prism.hpp
    include/quadrature_rules/Tetrahedron.hpp
    include/quadrature_rules/QuadraturePoint.hpp
    include/quadrature_rules/Triangle.hpp
    include/quadrature_rules/SurfaceRule.hpp
    include/quadrature_rules/Quadrangle.hpp
    include/quadrature_rules/Hexahedron.hpp
    include/quadrature_rules/VolumeRule.hpp
    )

set(libquadrature_SOURCES
    src/Line.cpp
    src/Quadrangle.cpp
    src/Hexahedron.cpp
    src/Prism.cpp
    src/Triangle.cpp
    src/SurfaceRule.cpp
    src/Tetrahedron.cpp
    )

add_library(libquadrature
    ${libquadrature_INCLUDES}
    ${libquadrature_SOURCES}
    )

set_target_properties(libquadrature PROPERTIES
	CXX_STANDARD 14
    CXX_EXTENSIONS OFF
    )

target_include_directories(libquadrature
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src
    )