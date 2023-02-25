cmake_minimum_required(VERSION 3.10)

project(selection
    LANGUAGES CXX
    )

find_package(Qt5 COMPONENTS Core Widgets OpenGL REQUIRED)

set(selection_INCLUDES
    include/selection/Selection.h++
    include/selection/ISelectionService.h++
    include/selection/SelectionService.h++
    )

set(selection_HEADERS
    )

set(selection_SOURCES
    src/Selection.c++
    src/SelectionService.c++
    )

add_library(${PROJECT_NAME} STATIC
    ${selection_INCLUDES}
    ${selection_HEADERS}
    ${selection_SOURCES}
    )

add_dependencies(${PROJECT_NAME}
    domain)

target_include_directories(${PROJECT_NAME}
    PUBLIC
      $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    )

set_target_properties(${PROJECT_NAME} PROPERTIES
	CXX_STANDARD 14
    CXX_EXTENSIONS OFF
    AUTOMOC ON
    AUTOUIC ON
)

target_link_libraries(${PROJECT_NAME}
    domain
    )
