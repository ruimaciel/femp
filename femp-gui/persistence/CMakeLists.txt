cmake_minimum_required(VERSION 3.10)

project(persistence
    LANGUAGES CXX
    VERSION 0.1.0
    )


set(persistence_INCLUDES
    include/persistence/ElementRepository.h++
    include/persistence/NodeRepository.h++
    include/persistence/MaterialRepository.h++
    include/persistence/LoadPatternRepository.h++
    )

set(persistence_HEADERS
    )

set(persistence_SOURCES
    src/ElementRepository.c++
    src/NodeRepository.c++
    src/MaterialRepository.c++
    src/LoadPatternRepository.c++
    )

add_library(${PROJECT_NAME} STATIC
    ${persistence_INCLUDES}
    ${persistence_HEADERS}
    ${persistence_SOURCES}
    )

add_dependencies(${PROJECT_NAME} domain application)

set_target_properties(${PROJECT_NAME} PROPERTIES
	CXX_STANDARD 14
    CXX_EXTENSIONS OFF
    )

target_include_directories(${PROJECT_NAME}
    PUBLIC
      $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    )

target_link_libraries(${PROJECT_NAME}
    domain
    application
    libfemp
    )
