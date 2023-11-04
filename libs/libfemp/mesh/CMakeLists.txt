cmake_minimum_required(VERSION 3.10)

project(libfemp
    LANGUAGES CXX
    VERSION 0.1.0
    )

set(libfemp_mesh_INCLUDES
    include/libfemp/mesh/MeshModel.hpp
    include/libfemp/mesh/Element.hpp
    include/libfemp/mesh/ElementVisitor.hpp
    include/libfemp/mesh/Node.hpp
    include/libfemp/mesh/elements/Tetrahedron4.hpp
    include/libfemp/mesh/elements/Tetrahedron10.hpp
    include/libfemp/mesh/elements/Tetrahedron20.hpp
    include/libfemp/mesh/elements/Tetrahedron35.hpp
    include/libfemp/mesh/elements/Tetrahedron56.hpp
    include/libfemp/mesh/elements/Hexahedron8.hpp
    include/libfemp/mesh/elements/Hexahedron20.hpp
    include/libfemp/mesh/elements/Hexahedron27.hpp
    include/libfemp/mesh/elements/Prism6.hpp
    include/libfemp/mesh/elements/Prism15.hpp
    include/libfemp/mesh/elements/Prism18.hpp
    )

set(libfemp_mesh_HEADERS
    src/MeshModelImpl.hpp
    )

set(libfemp_mesh_SOURCES
    src/MeshModelImpl.cpp
    src/Element.cpp
    src/elements/Tetrahedron4.cpp
    src/elements/Tetrahedron10.cpp
    src/elements/Tetrahedron20.cpp
    src/elements/Tetrahedron35.cpp
    src/elements/Tetrahedron56.cpp
    src/elements/Hexahedron8.cpp
    src/elements/Hexahedron20.cpp
    src/elements/Hexahedron27.cpp
    src/elements/Prism6.cpp
    src/elements/Prism15.cpp
    src/elements/Prism18.cpp
    src/Node.cpp
    )

add_library(libfemp_mesh
    ${libfemp_mesh_INCLUDES}
    ${libfemp_mesh_HEADERS}
    ${libfemp_mesh_SOURCES}
    )

target_include_directories(libfemp_mesh
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
    )
