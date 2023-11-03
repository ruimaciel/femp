cmake_minimum_required(VERSION 3.10) # due to googletest

project(femp
    LANGUAGES CXX
    VERSION 0.1.0
)

find_package(Qt5 COMPONENTS Core Widgets OpenGL REQUIRED)

set(OpenGL_GL_PREFERENCE "LEGACY")
find_package(OpenGL REQUIRED)
find_package(Boost REQUIRED COMPONENTS headers)

add_subdirectory(libs/libla)
add_subdirectory(libs/libquadrature)
add_subdirectory(libs/libfemp)
add_subdirectory(src/femp-gui)
add_subdirectory(src/femp-cli)

option(RUN_TESTS "Runs tests" OFF)
if(RUN_TESTS)
    enable_testing()
    add_subdirectory(tests)
endif()
