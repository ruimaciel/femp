cmake_minimum_required(VERSION 3.10)

project(libfemp_io
	LANGUAGES CXX
	)

set(libfemp_io_INCLUDES
	include/libfemp/io/import/Parser.hpp
	)

set(libfemp_io_HEADERS
    src/export/GmshExporter.hpp
    )

set(libfemp_io_SOURCES
    src/export/GmshExporter.cpp
    src/import/Parser.cpp
    )

add_library(libfemp_io
	${libfemp_io_INCLUDES}
	${libfemp_io_HEADERS}
	${libfemp_io_SOURCES}
	)

add_dependencies(libfemp_io
    libfemp_mesh
    )

target_link_libraries(libfemp_io
    libfemp_mesh
    )

set_target_properties(libfemp_io PROPERTIES
	CXX_STANDARD 14
	CXX_EXTENSIONS OFF
	)

target_include_directories(libfemp_io
	PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include
	PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src
	)
