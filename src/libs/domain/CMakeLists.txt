cmake_minimum_required(VERSION 4.2)

project(domain
    LANGUAGES CXX
    VERSION 0.1.0
    )

add_library(${PROJECT_NAME} STATIC)

target_sources(${PROJECT_NAME}
    PUBLIC FILE_SET HEADERS
        BASE_DIRS include
        FILES
            include/domain/Model.hpp
    PRIVATE
        src/Model.cpp
        src/ModelImpl.cpp
        src/ModelImpl.hpp
    )

set_target_properties(${PROJECT_NAME} PROPERTIES
	CXX_STANDARD 14
    CXX_EXTENSIONS OFF
    )

target_include_directories(${PROJECT_NAME}
    PUBLIC
      $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    )

target_link_libraries(${PROJECT_NAME}
    libfemp
    )

if(RUN_TESTS)
	add_subdirectory(tests)
endif(RUN_TESTS)
