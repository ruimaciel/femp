cmake_minimum_required(VERSION 3.1)

project(persistence
    LANGUAGES CXX
    VERSION 0.1.0
    )


set(persistence_INCLUDES
    include/persistence/ElementRepository.h++
    )

set(persistence_HEADERS
    )

set(persistence_SOURCES
    src/ElementRepository.c++
    )

add_library(${PROJECT_NAME} STATIC
    ${persistence_INCLUDES}
    ${persistence_HEADERS}
    ${persistence_SOURCES}
    )

set_target_properties(${PROJECT_NAME} PROPERTIES
    CXX_STANDARD 11
    CXX_EXTENSIONS OFF
    )

target_include_directories(${PROJECT_NAME}
    PUBLIC
      $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    )

target_link_libraries(${PROJECT_NAME}
    domain
    libfemp
    )
