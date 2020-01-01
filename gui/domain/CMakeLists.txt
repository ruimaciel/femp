cmake_minimum_required(VERSION 3.1)

project(domain
    LANGUAGES CXX
    VERSION 0.1.0
    )

set(domain_INCLUDES
    include/Model.h++
    )

set(domain_HEADERS
    src/ModelImpl.h++
    )

set(domain_SOURCES
    src/Model.c++
    src/ModelImpl.c++
    )

add_library(${PROJECT_NAME} STATIC
    ${domain_INCLUDES}
    ${domain_HEADERS}
    ${domain_SOURCES}
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
    libfemp
    )
