cmake_minimum_required(VERSION 3.1)

project(libfemp_io
	LANGUAGES CXX
	)

set(libfemp_io_INCLUDES
	include/libfemp/io/import/Parser.h++
	)

set(libfemp_io_HEADERS
	)

set(libfemp_io_SOURCES
	src/import/Parser.c++
	)

add_library(libfemp_io
	${libfemp_io_INCLUDES}
	${libfemp_io_HEADERS}
	${libfemp_io_SOURCES}
	)

set_target_properties(libfemp_io PROPERTIES
	CXX_STANDARD 14
	CXX_EXTENSIONS OFF
	)

target_include_directories(libfemp_io
	PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include
	PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src
	)
