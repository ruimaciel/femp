cmake_minimum_required(VERSION 3.1)

project(libfemp
    LANGUAGES CXX
    VERSION 0.1.0
    )

set(libfemp_mesh_INCLUDES
    include/libfemp/mesh/MeshModel.h++
    include/libfemp/mesh/Element.h++
    include/libfemp/mesh/ElementVisitor.h++
    include/libfemp/mesh/Node.h++
    include/libfemp/mesh/elements/Tetrahedron4.h++
    include/libfemp/mesh/elements/Tetrahedron10.h++
    include/libfemp/mesh/elements/Tetrahedron20.h++
    include/libfemp/mesh/elements/Tetrahedron35.h++
    include/libfemp/mesh/elements/Tetrahedron56.h++
    include/libfemp/mesh/elements/Hexahedron8.h++
    include/libfemp/mesh/elements/Hexahedron20.h++
    include/libfemp/mesh/elements/Hexahedron27.h++
    include/libfemp/mesh/elements/Prism6.h++
    include/libfemp/mesh/elements/Prism15.h++
    include/libfemp/mesh/elements/Prism18.h++
    )

set(libfemp_mesh_HEADERS
    src/MeshModelImpl.h++
    )

set(libfemp_mesh_SOURCES
    src/MeshModelImpl.c++
    src/Element.c++
    src/elements/Tetrahedron4.c++
    src/elements/Tetrahedron10.c++
    src/elements/Tetrahedron20.c++
    src/elements/Tetrahedron35.c++
    src/elements/Tetrahedron56.c++
    src/elements/Hexahedron8.c++
    src/elements/Hexahedron20.c++
    src/elements/Hexahedron27.c++
    src/elements/Prism6.c++
    src/elements/Prism15.c++
    src/elements/Prism18.c++
    src/Node.c++
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
