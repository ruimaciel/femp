cmake_minimum_required(VERSION 3.1)

project(application
    LANGUAGES CXX
    )

set(application_INCLUDES
    include/application/interfaces/IElementRepository.h++
    include/application/interfaces/INodeRepository.h++
    include/application/interfaces/IMaterialRepository.h++
    include/application/interfaces/ILoadPatternRepository.h++
    )

set(application_HEADERS
    )

set(application_SOURCES
    src/interfaces/IElementRepository.c++
    src/interfaces/INodeRepository.c++
    src/interfaces/IMaterialRepository.c++
    src/interfaces/ILoadPatternRepository.c++
    )

add_library(${PROJECT_NAME} STATIC
    ${application_INCLUDES}
    ${application_HEADERS}
    ${application_SOURCES}
    )

add_dependencies(${PROJECT_NAME} domain)

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
    )
